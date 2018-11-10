var md5 = require('md5');

module.exports = {
    // createMD5Hash4: function (password) {
    //     var pass = md5(password);
    //     pass = pass + "university";
    //     pass = md5(pass);
    //     return pass;
    // },
    // createMD5Hash2: function (password) {
    //     var pass = (md5(password)) + "university" ;
    //     pass = md5(pass);
    //     return pass;
    // },
    // createMD5Hash3: function (password) {
    //     var pass = md5((md5(password)) + "university") ;
    //     return pass;
    // },
    createMD5Hash: function (password) {
        return md5((md5(password)) + "university") ;
    }
};