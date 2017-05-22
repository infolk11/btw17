-- 1stimme
INSERT INTO `1stimme` (`W_ID`, `D_ID`, `1Anzahl`) VALUES
(1001, 2, 50);

INSERT INTO `1stimme` (`W_ID`, `D_ID`, `1Anzahl`) VALUES
(1001, 4, 24);

INSERT INTO `1stimme` (`W_ID`, `D_ID`, `1Anzahl`) VALUES
(1001, 5, 56);

INSERT INTO `1stimme` (`W_ID`, `D_ID`, `1Anzahl`) VALUES
(1001, 3, 24);

INSERT INTO `1stimme` (`W_ID`, `D_ID`, `1Anzahl`) VALUES
(1003, 1, 26);

INSERT INTO `1stimme` (`W_ID`, `D_ID`, `1Anzahl`) VALUES
(1003, 2, 40);

INSERT INTO `1stimme` (`W_ID`, `D_ID`, `1Anzahl`) VALUES
(1002, 4, 5);

INSERT INTO `1stimme` (`W_ID`, `D_ID`, `1Anzahl`) VALUES
(1003, 5, 33);

INSERT INTO `1stimme` (`W_ID`, `D_ID`, `1Anzahl`) VALUES
(1005, 1, 17);

-- 2stimme
INSERT INTO `2stimme` (`W_ID`, `P_ID`, `2Anzahl`) VALUES
(1001, 2, 78);

INSERT INTO `2stimme` (`W_ID`, `P_ID`, `2Anzahl`) VALUES
(1001, 3, 112);

INSERT INTO `2stimme` (`W_ID`, `P_ID`, `2Anzahl`) VALUES
(1001, 4, 76);

INSERT INTO `2stimme` (`W_ID`, `P_ID`, `2Anzahl`) VALUES
(1001, 5, 55);

INSERT INTO `2stimme` (`W_ID`, `P_ID`, `2Anzahl`) VALUES
(1002, 3, 11);

INSERT INTO `2stimme` (`W_ID`, `P_ID`, `2Anzahl`) VALUES
(1004, 2, 42);

INSERT INTO `2stimme` (`W_ID`, `P_ID`, `2Anzahl`) VALUES
(1003, 4, 60);

INSERT INTO `2stimme` (`W_ID`, `P_ID`, `2Anzahl`) VALUES
(1002, 4, 79);

INSERT INTO `2stimme` (`W_ID`, `P_ID`, `2Anzahl`) VALUES
(1004, 5, 22);

-- direktkandidaten

INSERT INTO `direktkandidaten` (`D_ID`, `Vorname`, `Name`, `P_ID`) VALUES
(2, 'Michael', 'Myers', '3');

INSERT INTO `direktkandidaten` (`D_ID`, `Vorname`, `Name`, `P_ID`) VALUES
(3, 'Testi', 'McTestface', '2');

INSERT INTO `direktkandidaten` (`D_ID`, `Vorname`, `Name`, `P_ID`) VALUES
(4, 'Walter', 'Meier', '4');

INSERT INTO `direktkandidaten` (`D_ID`, `Vorname`, `Name`) VALUES
(5, 'Gary', 'Eich');

-- partei

INSERT INTO `partei` (`P_ID`, `P_Bezeichnung`, `Farbe`, `Listenplaetze`) VALUES
(2, 'linke', 'gelb', 15);

INSERT INTO `partei` (`P_ID`, `P_Bezeichnung`, `Farbe`, `Listenplaetze`) VALUES
(3, 'obere', 'grün', 25);

INSERT INTO `partei` (`P_ID`, `P_Bezeichnung`, `Farbe`, `Listenplaetze`) VALUES
(4, 'untere', 'pink', 22);

INSERT INTO `partei` (`P_ID`, `P_Bezeichnung`, `Farbe`, `Listenplaetze`) VALUES
(5, 'mittlere', 'braun', 20);

-- wahllokal
 
INSERT INTO `wahllokal` (`W_ID`, `W_Bezeichnung`, `PLZ`, `Straße`, `Wahlberechtigte`, `Wahlbeteiliegung`) VALUES
(1012, 'Grunschule Gentz I', 16816, 'Gerhart-Hauptmann-Str. 38', 500, 400);

INSERT INTO `wahllokal` (`W_ID`, `W_Bezeichnung`, `PLZ`, `Straße`, `Wahlberechtigte`, `Wahlbeteiliegung`) VALUES
(1013, 'Stadtgarten', 16816, 'Karl-Marx-Str. 103', 187, 59);

INSERT INTO `wahllokal` (`W_ID`, `W_Bezeichnung`, `PLZ`, `Straße`, `Wahlberechtigte`, `Wahlbeteiliegung`) VALUES
(1014, 'Altes Gymnsium I', 16816, 'Am Alten Gymnasium 1', 637, 364);

INSERT INTO `wahllokal` (`W_ID`, `W_Bezeichnung`, `PLZ`, `Straße`, `Wahlberechtigte`, `Wahlbeteiliegung`) VALUES
(1015, 'Rosa-Luxemburg-Schule', 16816, 'Rosa-Luxemburg-Str. 16', 321, 123);

