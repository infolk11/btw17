-- phpMyAdmin SQL Dump
-- version 4.6.5.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Erstellungszeit: 20. Mai 2017 um 15:16
-- Server-Version: 10.1.21-MariaDB
-- PHP-Version: 7.1.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Datenbank: `wahl(17) 1.2.sql`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `1stimme`
--

CREATE TABLE `1stimme` (
  `W_ID` int(4) NOT NULL,
  `1Anzahl` int(4) NOT NULL,
  `D_ID` int(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;

--
-- Daten für Tabelle `1stimme`
--

INSERT INTO `1stimme` (`W_ID`, `1Anzahl`, `D_ID`) VALUES
(1010, 30, 0);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `2stimme`
--

CREATE TABLE `2stimme` (
  `W_ID` int(4) NOT NULL,
  `P_ID` int(2) NOT NULL,
  `2Anzahl` int(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;

--
-- Daten für Tabelle `2stimme`
--

INSERT INTO `2stimme` (`W_ID`, `P_ID`, `2Anzahl`) VALUES
(1010, 1, 101);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `direktkandidaten`
--

CREATE TABLE `direktkandidaten` (
  `D_ID` int(4) NOT NULL,
  `Vorname` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  `Name` varchar(255) COLLATE latin1_german2_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;

--
-- Daten für Tabelle `direktkandidaten`
--

INSERT INTO `direktkandidaten` (`D_ID`, `Vorname`, `Name`) VALUES
(1, 'Jack', 'Daniels');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `partei`
--

CREATE TABLE `partei` (
  `P_ID` int(2) NOT NULL,
  `P_Bezeichnung` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  `Farbe` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  `Listenplaetze` int(3) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;

--
-- Daten für Tabelle `partei`
--

INSERT INTO `partei` (`P_ID`, `P_Bezeichnung`, `Farbe`, `Listenplaetze`) VALUES
(1, 'rechte', 'rot', 20);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `wahllokal`
--

CREATE TABLE `wahllokal` (
  `W_ID` int(4) NOT NULL,
  `W_Bezeichnung` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  `PLZ` int(5) NOT NULL,
  `Straße` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  `Wahlberechtigte` int(4) NOT NULL,
  `Wahlbeteiligung` int(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;

--
-- Daten für Tabelle `wahllokal`
--

INSERT INTO `wahllokal` (`W_ID`, `W_Bezeichnung`, `PLZ`, `Straße`, `Wahlberechtigte`, `Wahlbeteiligung`) VALUES
(1010, 'Kita Regenbogen', 16816, 'Dorfstr. 23', 1087, 509);

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `1stimme`
--
ALTER TABLE `1stimme`
  ADD PRIMARY KEY (`W_ID`,`D_ID`),
  ADD KEY `W_ID` (`W_ID`) USING BTREE,
  ADD KEY `D_ID` (`W_ID`,`D_ID`) USING BTREE;

--
-- Indizes für die Tabelle `2stimme`
--
ALTER TABLE `2stimme`
  ADD PRIMARY KEY (`W_ID`,`P_ID`),
  ADD KEY `W_ID` (`W_ID`),
  ADD KEY `P_ID` (`P_ID`);

--
-- Indizes für die Tabelle `direktkandidaten`
--
ALTER TABLE `direktkandidaten`
  ADD PRIMARY KEY (`D_ID`);

--
-- Indizes für die Tabelle `partei`
--
ALTER TABLE `partei`
  ADD PRIMARY KEY (`P_ID`);

--
-- Indizes für die Tabelle `wahllokal`
--
ALTER TABLE `wahllokal`
  ADD PRIMARY KEY (`W_ID`);

--
-- Constraints der exportierten Tabellen
--

--
-- Constraints der Tabelle `1stimme`
--
ALTER TABLE `1stimme`
  ADD CONSTRAINT `1stimme_ibfk_1` FOREIGN KEY (`W_ID`) REFERENCES `wahllokal` (`W_ID`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
