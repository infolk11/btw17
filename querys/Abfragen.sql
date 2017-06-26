-- Durchschnitt gesamter Wahlbeteiligung (prozentual)
SELECT SUM(Wahlbeteiligung)/SUM(Wahlberechtigte)*100 AS Gesamtwahlbeteiligung FROM wahllokal;

-- Erststimmen pro Kandidaten
SELECT Vorname, Name, SUM(1Anzahl) AS Gesamtstimmen FROM 1stimme, direktkandidaten
WHERE 1stimme.D_ID = direktkandidaten.D_ID
GROUP BY 1stimme.D_ID
ORDER BY SUM(1Anzahl) DESC;


-- Erststimmen pro Kandidaten (prozentual)
SELECT Vorname, Name, SUM(1Anzahl)/(SELECT SUM(1Anzahl) FROM 1stimme)*100 AS Prozent FROM 1stimme, direktkandidaten
WHERE  1stimme.D_ID = direktkandidaten.D_ID
GROUP BY 1stimme.D_ID
HAVING Prozent >= 3
ORDER BY Prozent DESC;

-- Erststimmen pro Kandidaten (prozentual) zum Vergleich (bei weniger als 5 Direktkandidaten Variable 0 setzen)
SET @d = 0;

SELECT Vorname, Name, SUM(1Anzahl)/(SELECT SUM(1Anzahl) FROM 1stimme)*100 AS Prozent FROM 1stimme, direktkandidaten
WHERE 1stimme.D_ID = direktkandidaten.D_ID
AND 1stimme.D_ID = @d
GROUP BY 1stimme.D_ID;

-- Stimmen pro Partei
SELECT P_Bezeichnung, SUM(2Anzahl) AS Gesamtstimmen FROM 2stimme, partei
WHERE 2stimme.P_ID = partei.P_ID
GROUP BY 2stimme.P_ID
ORDER BY SUM(2Anzahl) DESC;


-- Stimmen pro Partei (prozentual)
SELECT P_Bezeichnung, SUM(2Anzahl)/(SELECT SUM(2Anzahl) FROM 2stimme)*100 AS Prozent FROM 2stimme, partei
WHERE 2stimme.P_ID = partei.P_ID
GROUP BY 2stimme.P_ID
HAVING Prozent >= 3
ORDER BY Prozent DESC;
SET @p = 2;

-- Stimmen pro Partei (prozentual) zum Vergleich (bei weniger als 5 Parteien Variable 0 setzen)
SET @p = 0;

SELECT P_Bezeichnung, SUM(2Anzahl)/(SELECT SUM(2Anzahl) FROM 2stimme)*100 AS Prozent FROM 2stimme, partei
WHERE partei.P_ID = 2stimme.P_ID
AND 2stimme.P_ID = @p
GROUP BY 2stimme.P_ID



