var app = require('express')();
var mongoose = require('mongoose');
var http = require('http').Server(app);
var io = require('socket.io')(http);

var conString = "mongodb://ramgopal18998:qwertyuiop@ds119489.mlab.com:19489/dummy";

mongoose.connect(conString,function(err,db){
    console.log("DB is connected");
    
app.get('/', function(req, res){
  res.sendFile(__dirname + '/index.html');
});
io.on('connection', function(socket){
	var col = db.collection('Message');
	col.find().limit(100).sort({__id:1}).toArray(function(err,res){
  if(err) throw err;
socket.emit('total',res);
});


  socket.on('chat message', function(msg){
  	
  	col.insert({name:msg.name,message:msg.message},function(){
  		console.log("added");
  	});

	console.log('message: ' + msg.message);
    io.sockets.emit('chat message',msg);
  });
});	


http.listen(3000, function(){
  console.log('listening on *:3000');
});


});







