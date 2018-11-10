module.exports = {
    sendResponse: function (functionName, status, titleMsg, textMsg,data1) {
        var data = {
            status: true,
            functionName: functionName,
            result: {
                status: status,
                titleMsg: titleMsg,
                textMsg: textMsg,
                data: data1
            }
        };
        return (JSON.stringify(data));
    }
};