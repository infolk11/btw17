-- phpMyAdmin SQL Dump
-- version 4.6.5.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Erstellungszeit: 07. Apr 2017 um 01:01
-- Server-Version: 10.1.21-MariaDB
-- PHP-Version: 7.1.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Datenbank: `wahl17`
--
CREATE DATABASE IF NOT EXISTS `wahl17` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `wahl17`;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `1stimme`
--

DROP TABLE IF EXISTS `1stimme`;
CREATE TABLE IF NOT EXISTS `1stimme` (
  `W_ID` int(4) NOT NULL,
  `D_ID` int(4) NOT NULL,
  `1Anzahl` int(4) NOT NULL,
  PRIMARY KEY (`W_ID`,`D_ID`),
  UNIQUE KEY `D_ID_2` (`D_ID`),
  KEY `W_ID` (`W_ID`),
  KEY `D_ID` (`D_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- TRUNCATE Tabelle vor dem Einfügen `1stimme`
--

TRUNCATE TABLE `1stimme`;
--
-- Daten für Tabelle `1stimme`
--

INSERT INTO `1stimme` (`W_ID`, `D_ID`, `1Anzahl`) VALUES
(1010, 1, 30);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `2stimme`
--

DROP TABLE IF EXISTS `2stimme`;
CREATE TABLE IF NOT EXISTS `2stimme` (
  `W_ID` int(4) NOT NULL,
  `P_ID` int(2) NOT NULL,
  `2Anzahl` int(4) NOT NULL,
  PRIMARY KEY (`W_ID`,`P_ID`),
  KEY `W_ID` (`W_ID`),
  KEY `P_ID` (`P_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- TRUNCATE Tabelle vor dem Einfügen `2stimme`
--

TRUNCATE TABLE `2stimme`;
--
-- Daten für Tabelle `2stimme`
--

INSERT INTO `2stimme` (`W_ID`, `P_ID`, `2Anzahl`) VALUES
(1010, 1, 101);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `direktkandidaten`
--

DROP TABLE IF EXISTS `direktkandidaten`;
CREATE TABLE IF NOT EXISTS `direktkandidaten` (
  `D_ID` int(4) NOT NULL,
  `Vorname` varchar(255) CHARACTER SET latin1 COLLATE latin1_german2_ci NOT NULL,
  `Name` varchar(255) CHARACTER SET latin1 COLLATE latin1_german2_ci NOT NULL,
  PRIMARY KEY (`D_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- TRUNCATE Tabelle vor dem Einfügen `direktkandidaten`
--

TRUNCATE TABLE `direktkandidaten`;
--
-- Daten für Tabelle `direktkandidaten`
--

INSERT INTO `direktkandidaten` (`D_ID`, `Vorname`, `Name`) VALUES
(1, 'Jack', 'Daniels');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `partei`
--

DROP TABLE IF EXISTS `partei`;
CREATE TABLE IF NOT EXISTS `partei` (
  `P_ID` int(2) NOT NULL,
  `P_Bezeichnung` varchar(255) CHARACTER SET latin1 COLLATE latin1_german2_ci NOT NULL,
  `Farbe` varchar(255) CHARACTER SET latin1 COLLATE latin1_german2_ci NOT NULL,
  `Listenplaetze` int(3) NOT NULL,
  PRIMARY KEY (`P_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- TRUNCATE Tabelle vor dem Einfügen `partei`
--

TRUNCATE TABLE `partei`;
--
-- Daten für Tabelle `partei`
--

INSERT INTO `partei` (`P_ID`, `P_Bezeichnung`, `Farbe`, `Listenplaetze`) VALUES
(1, 'rechte', 'rot', 20);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `wahllokal`
--

DROP TABLE IF EXISTS `wahllokal`;
CREATE TABLE IF NOT EXISTS `wahllokal` (
  `W_ID` int(4) NOT NULL,
  `W_Bezeichnung` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  `PLZ` int(5) NOT NULL,
  `Straße` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  `Wahlberechtigte` int(4) NOT NULL,
  `Wahlbeteiliegung` int(4) NOT NULL,
  PRIMARY KEY (`W_ID`),
  UNIQUE KEY `W_ID` (`W_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;

--
-- TRUNCATE Tabelle vor dem Einfügen `wahllokal`
--

TRUNCATE TABLE `wahllokal`;
--
-- Daten für Tabelle `wahllokal`
--

INSERT INTO `wahllokal` (`W_ID`, `W_Bezeichnung`, `PLZ`, `Straße`, `Wahlberechtigte`, `Wahlbeteiliegung`) VALUES
(1010, 'Kita Regenbogen', 16816, 'Dorfstr. 23', 1087, 509);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
