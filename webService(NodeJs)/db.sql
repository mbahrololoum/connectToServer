/*
 Navicat Premium Data Transfer

 Source Server         : Mac Masoud
 Source Server Type    : MySQL
 Source Server Version : 50542
 Source Host           : localhost:3306
 Source Schema         : db

 Target Server Type    : MySQL
 Target Server Version : 50542
 File Encoding         : 65001

 Date: 10/11/2018 16:10:13
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for tbl_contact
-- ----------------------------
DROP TABLE IF EXISTS `tbl_contact`;
CREATE TABLE `tbl_contact` (
  `name` varchar(20) COLLATE utf8_persian_ci DEFAULT NULL,
  `family` varchar(30) COLLATE utf8_persian_ci DEFAULT NULL,
  `phoneNumber` varchar(11) COLLATE utf8_persian_ci NOT NULL,
  `favority` tinyint(1) DEFAULT NULL,
  `gender` varchar(10) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`phoneNumber`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of tbl_contact
-- ----------------------------
BEGIN;
INSERT INTO `tbl_contact` VALUES ('masoud', 'bahrololoum', '09122221111', 0, 'Female');
INSERT INTO `tbl_contact` VALUES ('mehti', 'rezazadeh', '09122221112', 1, 'Female');
INSERT INTO `tbl_contact` VALUES ('masoud', 'bahrololoum', '09122221113', 1, 'Female');
INSERT INTO `tbl_contact` VALUES ('ali', 'ahmadi', '09122221114', 1, 'Male');
INSERT INTO `tbl_contact` VALUES ('masoud', 'bahrololoum', '09122221117', 0, 'Female');
INSERT INTO `tbl_contact` VALUES ('masoud', 'bahrololoum', '09122221118', 1, 'Female');
INSERT INTO `tbl_contact` VALUES ('Ali', 'Rezaie', '09188888888', 1, 'Male');
INSERT INTO `tbl_contact` VALUES ('e', 'e', '09222222222', 1, 'Female');
INSERT INTO `tbl_contact` VALUES ('1', '2', '09999999999', 0, 'Male');
COMMIT;

-- ----------------------------
-- Table structure for tbl_users
-- ----------------------------
DROP TABLE IF EXISTS `tbl_users`;
CREATE TABLE `tbl_users` (
  `username` varchar(10) COLLATE utf8_persian_ci NOT NULL,
  `password` varchar(10) COLLATE utf8_persian_ci DEFAULT NULL,
  `name` varchar(20) COLLATE utf8_persian_ci DEFAULT NULL,
  `family` varchar(30) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of tbl_users
-- ----------------------------
BEGIN;
INSERT INTO `tbl_users` VALUES ('09', '1', 'masoud', 'bahrololoum');
COMMIT;

SET FOREIGN_KEY_CHECKS = 1;
