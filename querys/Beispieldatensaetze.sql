-- direktkandidaten
INSERT INTO Direktkandidaten (D_ID, Vorname, Name) VALUES
(2, 'Michael', 'Myers'),
(3, 'Testi', 'McTestface'),
(4, 'Walter', 'Meier'),
(5, 'Gary', 'Eich'),
(1, 'Jack', 'Daniels');


-- partei
INSERT INTO Partei (P_ID, P_Bezeichnung, Farbe, Listenplaetze) VALUES
(2, 'linke', 'gelb', 15),
(3, 'obere', 'grün', 25),
(4, 'untere', 'pink', 22),
(5, 'mittlere', 'braun', 20),
(1, 'rechte', 'rot', 20);

-- Daten für Tabelle `wahllokal`
INSERT INTO `Wahllokal` (`W_ID`, `W_Bezeichnung`, `PLZ`, `Straße`, `Wahlberechtigte`, `Wahlbeteiligung`) VALUES
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

INSERT INTO stellt(P_ID, D_ID) VALUES
(1,1),
(2,2),
(3,3),
(4,4),
(5,5);

-- 1stimme
INSERT INTO 1stimme (W_ID, D_ID, 1Anzahl) VALUES
(1010, 2, 50),
(1010, 4, 24),
(1010, 5, 56),
(1010, 3, 24),
(1013, 1, 26),
(1013, 2, 40),
(1012, 4, 5),
(1013, 5, 33),
(1015, 1, 17);

-- 2stimme
INSERT INTO 2stimme (W_ID, P_ID, 2Anzahl) VALUES
(1010, 2, 78),
(1010, 3, 112),
(1010, 4, 76),
(1010, 5, 55),
(1012, 3, 11),
(1014, 2, 42),
(1013, 4, 60),
(1012, 4, 79),
(1014, 5, 22),
(1010, 1, 101);
