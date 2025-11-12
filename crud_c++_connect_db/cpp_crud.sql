/*
 Navicat Premium Data Transfer

 Source Server         : cpp_algoritma
 Source Server Type    : MySQL
 Source Server Version : 100244
 Source Host           : 127.0.0.1:31235
 Source Schema         : cpp_crud

 Target Server Type    : MySQL
 Target Server Version : 100244
 File Encoding         : 65001

 Date: 12/11/2025 17:30:36
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for mahasiswa
-- ----------------------------
DROP TABLE IF EXISTS `mahasiswa`;
CREATE TABLE `mahasiswa`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `nama` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `nim` bigint NULL DEFAULT NULL,
  `asal_kampus` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `jurusan` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `fakultas` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
