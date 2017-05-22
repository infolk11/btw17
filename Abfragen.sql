-- Durchschnitt gesamter Wahlbeteiligung (prozentual)
SELECT sum(Wahlbeteiligung)/sum(Wahlberechtigte)*100 as Gesamtwahlbeteiligung from wahllokal;

-- Erststimmen pro Kandidaten
SELECT Vorname, Name, sum(1Anzahl) as Gesamtstimmen FROM 1stimme, direktkandidaten
WHERE 1stimme.D_ID = direktkandidaten.D_ID
GROUP BY 1stimme.D_ID
ORDER BY sum(1Anzahl) desc;


-- Erststimmen pro Kandidatem (prozentual)
SELECT Vorname, Name, sum(1Anzahl)/(SELECT sum(1Anzahl) from 1stimme)*100 as Prozent from 1stimme, direktkandidaten
WHERE  1stimme.D_ID = direktkandidaten.D_ID
GROUP BY 1stimme.D_ID
HAVING Prozent >= 3
ORDER BY Prozent desc;

-- Erststimmen pro Kandidatem (prozentual) zum Vergleich (bei weniger als 5 Direktkandidaten Variable 0 setzen)
SET @d1 = 0;
SET @d2 = 0;
SET @d3 = 0;
SET @d4 = 0;
SET @d5 = 0;

SELECT Vorname, Name, sum(1Anzahl)/(SELECT sum(1Anzahl) from 1stimme)*100 as Prozent from 1stimme, direktkandidaten
WHERE 1stimme.D_ID = direktkandidaten.D_ID
AND 1stimme.D_ID in (@d1, @d2, @d3, @d4, @d5)
GROUP BY 1stimme.D_ID;

-- Stimmen pro Partei
SELECT P_Bezeichnung, sum(2Anzahl) as Gesamtstimmen FROM 2stimme, partei
WHERE 2stimme.P_ID = partei.P_ID
GROUP BY 2stimme.P_ID
ORDER BY sum(2Anzahl) desc;


-- Stimmen pro Partei (prozentual)
SELECT P_Bezeichnung, sum(2Anzahl)/(SELECT sum(2Anzahl) from 2stimme)*100 as Prozent from 2stimme, partei
WHERE 2stimme.P_ID = partei.P_ID
GROUP BY 2stimme.P_ID
HAVING Prozent >= 3
ORDER BY Prozent desc;
SET @p = 2;

-- Stimmen pro Partei (prozentual) zum Vergleich (bei weniger als 5 Parteien Variable 0 setzen)
SET @p1 = 0;
SET @p2 = 0;
SET @p3 = 0;
SET @p4 = 0;
SET @p5 = 0;

SELECT P_Bezeichnung, sum(2Anzahl)/(SELECT sum(2Anzahl) from 2stimme)*100 as Prozent from 2stimme, partei
WHERE partei.P_ID = 2stimme.P_ID
AND 2stimme.P_ID in (@p1, @p2, @p3, @p4, @p5)
GROUP BY 2stimme.P_ID



