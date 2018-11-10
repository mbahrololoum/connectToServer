var isSQLInjection = require('is-sql-injection');

module.exports = {
    securityHandling: function (req) {
        if(isSQLInjection(req)) {
            return true;
        }else {
            return false;
        }
    },
    showError: function (functionName) {
        var data = {
            status: true,
            functionName: functionName,
            result: {
                status: false,
                titleMsg: "خطا",
                textMsg: "داده های ورودی نامعتبر است"
            }
        };
        return (JSON.stringify(data));
    }
};