-- phpMyAdmin SQL Dump
-- version 4.7.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Erstellungszeit: 22. Mai 2017 um 23:16
-- Server-Version: 10.1.22-MariaDB
-- PHP-Version: 7.1.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Datenbank: `wahl17`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `1stimme`
--

CREATE TABLE `1stimme` (
  `W_ID` int(4) NOT NULL,
  `D_ID` int(4) NOT NULL,
  `1Anzahl` int(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;

--
-- Daten für Tabelle `1stimme`
--

INSERT INTO `1stimme` (`W_ID`, `D_ID`, `1Anzahl`) VALUES
(1010, 1, 30);

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
  `Nachname` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  `P_ID` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;

--
-- Daten für Tabelle `direktkandidaten`
--

INSERT INTO `direktkandidaten` (`D_ID`, `Vorname`, `Nachname`, `P_ID`) VALUES
(1, 'Jack', 'Daniels', 0);

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
(1, 'rechte', '#e93f4c', 20);

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
(1001, 'Kita Storchennest', 16816, 'Gentzstr. 21', 0, 0),
(1002, 'Grundschule Gentz I', 16816, 'Gerhart-Hauptmann-Str. 38', 0, 0),
(1003, 'Stadtgarten', 16816, 'Karl-Marx-Str. 103', 0, 0),
(1004, 'Altes Gymnasium I', 16816, 'Am Alten Gymnasium 1', 0, 0),
(1005, 'Rosa-Luxemburg-Schule', 16816, 'Rosa-Luxemburg-Str. 16', 0, 0),
(1006, 'Grundschule Gildenhall', 16816, 'Hermsdorfer Weg 1', 0, 0),
(1007, 'Kita Birkengrund I', 16816, 'Birkengrund 14', 0, 0),
(1008, 'Kita Birkengrund II', 16816, 'Birkengrund 14', 0, 0),
(1009, 'Predigerwitwenhaus', 16816, 'Fischbänkenstr. 8', 0, 0),
(1010, 'Altes Gymnasium II', 16816, 'Am Alten Gymnsium 1', 0, 0),
(1011, 'Alexander-Puschkin-Schule', 16816, 'Puschkinstr. 5b', 0, 0),
(1012, 'NWG', 16816, 'Kränzliner Str. 32', 0, 0),
(1013, 'Begegnungsstätte ASB', 16816, 'Franz-Maecker-Str. 28', 0, 0),
(1014, 'Feuerwehr Bechlin', 16816, 'Schulstr. 103a', 0, 0),
(1015, 'Grundschule Gentz II', 16816, 'Gerhart-Hauptmann-Str. 38', 0, 0),
(1016, 'Kita Kunterbunt I', 16816, 'Artur-Becker-Str. 16', 0, 0),
(1017, 'Kita Kunterbunt II\r\n', 16816, 'Artur-Becker-Str. 16', 0, 0),
(1018, 'Schinkelgymnasium I\r\n', 16816, 'Käthe-Kollwitz-Str. 2\r\n', 0, 0),
(1019, 'Schinkelgymnasium II\r\n', 16816, 'Käthe-Kollwitz-Str. 2\r\n', 0, 0),
(1020, 'Karl-Liebknecht-Schule I\r\n', 16816, 'Franz-Mehring-Str. 1a\r\n', 0, 0),
(1021, 'Karl-Liebknecht-Schule II\r\n', 16816, 'Franz-Mehring-Str. 1a\r\n', 0, 0),
(1022, 'Treskow I\r\n', 16816, 'Nauener Str. 5\r\n', 0, 0),
(1023, 'Treskow II\r\n', 16816, 'Nauener Str. 5\r\n', 0, 0),
(1024, 'Altruppin I\r\n', 16827, 'Alt Ruppin, Friedrich-Engels-Str. 43\r\n', 0, 0),
(1025, 'Altruppin II\r\n', 16827, 'Alt Ruppin, Am Weinberg 1\r\n', 0, 0),
(1026, 'Altruppin III\r\n', 16827, 'Alt Ruppin, Am Weinberg 1\r\n', 0, 0),
(1027, 'Buskow\r\n', 16816, 'Buskower Dorfstr. 47b\r\n', 0, 0),
(1028, 'Gnewikow\r\n', 16818, 'Gutsstr. 23\r\n', 0, 0),
(1029, 'Gühlen-Glienicke\r\n', 16818, 'Dorfstr. 23a\r\n', 0, 0),
(1030, 'Karwe\r\n', 16818, 'Lange Str. 32\r\n', 0, 0),
(1031, 'Krangen\r\n', 16816, 'Dorfstr. 2\r\n', 0, 0),
(1032, 'Lichtenberg\r\n', 16818, 'Dorfstr. 36\r\n', 0, 0),
(1033, 'Molchow\r\n', 16827, 'Krangener Str. 26\r\n', 0, 0),
(1034, 'Nietwerder\r\n', 16816, 'Dorfstr. 57\r\n', 0, 0),
(1035, 'Radensleben\r\n', 16818, 'Dorfstr. 97\r\n', 0, 0),
(1036, 'Stöffin\r\n', 16833, 'Dorfstr. 49a\r\n', 0, 0),
(1037, 'Wulkow\r\n', 16835, 'Nietwerderweg 13a\r\n', 0, 0),
(1038, 'Wuthenow\r\n', 16818, 'Dorfstr. 53\r\n', 0, 0);

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `1stimme`
--
ALTER TABLE `1stimme`
  ADD PRIMARY KEY (`W_ID`,`D_ID`),
  ADD UNIQUE KEY `D_ID_2` (`D_ID`),
  ADD KEY `W_ID` (`W_ID`),
  ADD KEY `D_ID` (`D_ID`);

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
  ADD PRIMARY KEY (`D_ID`),
  ADD UNIQUE KEY `P_ID` (`P_ID`);

--
-- Indizes für die Tabelle `partei`
--
ALTER TABLE `partei`
  ADD PRIMARY KEY (`P_ID`);

--
-- Indizes für die Tabelle `wahllokal`
--
ALTER TABLE `wahllokal`
  ADD PRIMARY KEY (`W_ID`),
  ADD UNIQUE KEY `W_ID` (`W_ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
