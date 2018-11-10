var mysql = require('mysql');

//start mysql connection
var connection = mysql.createConnection({
  host     : 'localhost',                     //mysql database host name
  user     : 'root',                          //mysql database user name
  password : '771414',                        //mysql database password
  database : 'db'                         //mysql database name
});

connection.connect(function(err) {
  if (err) throw err
  console.log('You are now connected with mysql database...')
}) 

module.exports = connection;
