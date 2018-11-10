var express   = require('express');
var api       = require('./service/API');
var router    = express.Router();

router.route('/login').post(api.login);
router.route('/createNewContact').post(api.createNewContact);
router.route('/checkContact').post(api.checkContact);
router.route('/deleteContact').post(api.deleteContact);
router.route('/deleteContactList').post(api.deleteContactList);
router.route('/contactList').post(api.contactList);

module.exports = router;