--
-- Tabellenstruktur für Tabelle `direktkandidaten`
--

CREATE TABLE `direktkandidaten` (
  `D_ID` int(4) NOT NULL,
  `Vorname` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  `Name` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  PRIMARY KEY (D_ID)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;

--
-- Tabellenstruktur für Tabelle `partei`
--

CREATE TABLE `partei` (
  `P_ID` int(2) NOT NULL,
  `P_Bezeichnung` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  `Farbe` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  `Listenplaetze` int(3) NOT NULL,
  PRIMARY KEY (P_ID)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;

--
-- Tabellenstruktur für Tabelle `wahllokal`
--

CREATE TABLE `wahllokal` (
  `W_ID` int(4) NOT NULL,
  `W_Bezeichnung` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  `PLZ` int(5) NOT NULL,
  `Straße` varchar(255) COLLATE latin1_german2_ci NOT NULL,
  `Wahlberechtigte` int(4) NOT NULL,
  `Wahlbeteiligung` int(4) NOT NULL,
  PRIMARY KEY (W_ID)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;

--
-- Tabellenstruktur für Tabelle `1stimme`
--

CREATE TABLE `1stimme` (
  `W_ID` int(4) NOT NULL,
  `D_ID` int(2) NOT NULL,
  `1Anzahl` int(2) NOT NULL,
  PRIMARY KEY(W_ID, D_ID),
  FOREIGN KEY (W_ID) REFERENCES wahllokal(W_ID),
  FOREIGN KEY (D_ID) REFERENCES direktkandidaten(D_ID)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;

--
-- Tabellenstruktur für Tabelle `2stimme`
--

CREATE TABLE `2stimme` (
  `W_ID` int(4) NOT NULL,
  `P_ID` int(2) NOT NULL,
  `2Anzahl` int(4) NOT NULL,
  PRIMARY KEY (W_ID, P_ID),
  FOREIGN KEY (W_ID) REFERENCES wahllokal(W_ID),
  FOREIGN KEY (P_ID) REFERENCES partei(P_ID)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;

CREATE TABLE stellt (
    P_ID int(2),
    D_ID int(4),
    PRIMARY KEY (P_ID, D_ID),
    FOREIGN KEY (P_ID) REFERENCES partei(P_ID),
    FOREIGN KEY (D_ID) REFERENCES direktkandidaten(D_ID)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_german2_ci ROW_FORMAT=COMPACT;


COMMIT;

