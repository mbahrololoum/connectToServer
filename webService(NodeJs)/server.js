var http           = require('http');
var express        = require('express');
var app            = express();
var bodyParser     = require('body-parser');
var routes         = require('./serviceRoutes');

app.use(bodyParser.json());        // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({ extended: true }));

app.use('/service', routes);

//create app server
var server = app.listen(3003,  "127.0.0.1", function () {
    var host = server.address().address;
    var port = server.address().port;
    console.log("Example app listening at http://%s:%s", host, port)
});
