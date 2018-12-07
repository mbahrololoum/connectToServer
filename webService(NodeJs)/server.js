var https          = require('https');
var express        = require('express');
var app            = express();
var fs             = require('fs');
var bodyParser     = require('body-parser');
var routes         = require('./serviceRoutes');

app.use(bodyParser.json());        // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({ extended: true }));

app.use('/service', routes);

var options = {
    key:  fs.readFileSync('key1.pem'),
    cert: fs.readFileSync('cert1.pem')
};

//create app server
var server = https.createServer(options, app).listen(3003, "127.0.0.1", function () {
    var host = server.address().address;
    var port = server.address().port;
    console.log("Example app listening at https://%s:%s", host, port)
});
