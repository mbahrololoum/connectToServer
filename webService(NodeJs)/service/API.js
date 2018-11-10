var sql            = require('../dataBase');
var sendRes        = require('../sendResponse');
var securHandling  = require('../securityHandling');
var sleep          = require('system-sleep');


module.exports = {
    login: function (req, res) {
        res.charset = 'utf-8';
        res.set({'Content-Type': 'applicastion/json'});

        sleep(1000);

        if (req.body.data.username=="") {
            return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Please insert username."));
        }
        if (req.body.data.password=="" || req.body.data.course_id <1) {
            return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Please insert password."));
        }
        if (securHandling.securityHandling([req.body.data.username,req.body.data.password])) {
            return res.end(securHandling.showError(req.body.functionName));
        }

        sql.query("SELECT name, family FROM tbl_users WHERE username = ? AND password = ? ",[req.body.data.username, req.body.data.password] , function (error, results) {
            if (error) {
                return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Please try again!"));
            } else {

                if(JSON.stringify(results) !== '[]'){
                    var field = {
                        "name":    results[0].name,
                        "family":  results[0].family
                    };
                    return res.end(sendRes.sendResponse(req.body.functionName,true, "", "",field));
                }
                else {
                  return res.end(sendRes.sendResponse(req.body.functionName,false, "Warning", "Incorrect Username or password!"));
              }
          }
      })
    },


    createNewContact: function (req, res) {
        res.charset = 'utf-8';
        res.set({'Content-Type': 'applicastion/json'});
        sleep(1000);

        if (req.body.data.name=="") {
            return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Please insert name."));
        }
        if (req.body.data.family=="" || req.body.data.course_id <1) {
            return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Please insert family."));
        }
        if (req.body.data.phoneNumber=="" || req.body.data.course_id <1) {
            return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Please insert phoneNumber."));
        }
        if (securHandling.securityHandling([req.body.data.username,req.body.data.password])) {
            return res.end(securHandling.showError(req.body.functionName));
        }

        sql.query("INSERT INTO tbl_contact (name, family, phoneNumber, favority, gender) VALUES (?, ?, ?, ?, ?);", [req.body.data.name, req.body.data.family, req.body.data.phoneNumber, req.body.data.favority, req.body.data.gender] , function (error, results) {
            if (error) {
                return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Please try again!"));
            } else {

                 //console.log("results  ===== " + results.affectedRows);
                 //return res.end(JSON.stringify(results));

                 if (results.affectedRows > 0 ) {
                    return res.end(sendRes.sendResponse(req.body.functionName,true, "", ""));
                } else {
                 return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Error whene insert info!"));
             }
         }
     })
    },


    checkContact: function (req, res) {
        res.charset = 'utf-8';
        res.set({'Content-Type': 'applicastion/json'});
        sleep(1000);

        if (req.body.data.phoneNumber=="") {
            return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Please insert phoneNumber."));
        }

        sql.query("SELECT name, family, favority, gender FROM tbl_contact WHERE phoneNumber = ? ;", req.body.data.phoneNumber, function (error, result, fields) {
            if (error) {
                return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Please try again!"));
            } else {

               if(JSON.stringify(result) !== '[]'){
                var field = {
                    name:      result[0].name,
                    family:    result[0].family,
                    favority:  result[0].favority,
                    gender:    result[0].gender
                };
                
                return res.end(sendRes.sendResponse(req.body.functionName,true, "", "",field));
            } else {
             return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Contact could not exit!"));
         }
     }
 })
    },


    deleteContact: function (req, res) {
        res.charset = 'utf-8';
        res.set({'Content-Type': 'applicastion/json'});
        sleep(1000);

        if (req.body.data.phoneNumber=="") {
            return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Please insert phoneNumber."));
        }

        sql.query("Delete FROM tbl_contact WHERE phoneNumber = ? ;", req.body.data.phoneNumber, function (error, result, fields) {
            if (error) {
                return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Cannot delete contact"));
            } else {

                if(result.affectedRows > 0){
                    return res.end(sendRes.sendResponse(req.body.functionName,true, "", ""));
                } else {
                 return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Contact Not Exist"));
             }
         }
     })
    },


    deleteContactList: function (req, res) {
        res.charset = 'utf-8';
        res.set({'Content-Type': 'applicastion/json'});
        sleep(1000);

        if (req.body.data.phoneNumber=="") {
            return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Please insert phoneNumber."));
        }

        var strQuery = "Delete FROM tbl_contact WHERE phoneNumber IN ("+req.body.data.phoneNumber+");";
        sql.query(strQuery, function (error, result, fields) {
            if (error) {
                return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Cannot delete contact"));
            } else {

                if(result.affectedRows > 0){
                    return res.end(sendRes.sendResponse(req.body.functionName,true, "", ""));
                } else {
                 return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Contact Not Exist"));
             }
         }
     })
    },


    contactList: function (req, res) {
        res.charset = 'utf-8';
        res.set({'Content-Type': 'applicastion/json'});
        sleep(1000);

        sql.query("SELECT name, family, phoneNumber, favority, gender FROM tbl_contact ", function (error, result, fields) {
            if (error) {
                return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Cannot select contact list"));
            } else {

             if(JSON.stringify(result) !== '[]'){
                var info = [];
                for (var i in result) {
                    var field = {
                        "name":        result[i].name,
                        "family":      result[i].family,
                        "phoneNumber": result[i].phoneNumber,
                        "favority":    result[i].favority,
                        "gender":      result[i].gender
                    };
                    info.push(field);
                }
                return res.end(sendRes.sendResponse(req.body.functionName,true, "", "",info));
            } else {
               return res.end(sendRes.sendResponse(req.body.functionName,false, "Error", "Contact Not Exist"));
           }
       }
   })
    }


};



















