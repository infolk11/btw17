-- Durchschnitt gesamter Wahlbeteiligung (prozentual)
SELECT sum(Wahlbeteiliegung)/sum(Wahlberechtigte)*100 as Gesamtwahlbeteiligung from wahllokal;

-- Erststimmen pro Kandidaten
SELECT Vorname, Name, sum(1Anzahl) as Gesamtstimmen FROM 1stimme, direktkandidaten
WHERE 1stimme.D_ID = direktkandidaten.D_ID
GROUP BY 1stimme.D_ID
ORDER BY sum(1Anzahl) desc
LIMIT 10;

-- Erststimmen pro Kandidatem (prozentual)
SELECT Vorname, Name, sum(1Anzahl)/(SELECT sum(1Anzahl) from 1stimme)*100 as Prozent from 1stimme, direktkandidaten
WHERE  1stimme.D_ID = direktkandidaten.D_ID
GROUP BY 1stimme.D_ID
HAVING Prozent >= 3
ORDER BY Prozent desc;


-- Stimmen pro Partei
SELECT P_Bezeichnung, sum(2Anzahl) as Gesamtstimmen FROM 2stimme, partei
WHERE 2stimme.P_ID = partei.P_ID
GROUP BY 2stimme.P_ID
ORDER BY sum(2Anzahl) desc
LIMIT 10;
-- Stimmen pro Partei (prozentual)
SELECT P_Bezeichnung, sum(2Anzahl)/(SELECT sum(2Anzahl) from 2stimme)*100 as Prozent from 2stimme, partei
WHERE 2stimme.P_ID = partei.P_ID
GROUP BY 2stimme.P_ID
HAVING Prozent >= 3
ORDER BY Prozent desc;


-- Neuruppiner Bundestag

SELECT P_Bezeichnung, sum(2Anzahl)/(SELECT sum(2Anzahl) from 2stimme)*100 as Prozent from 2stimme, partei
WHERE 2stimme.P_ID = partei.P_ID
GROUP BY 2stimme.P_ID
ORDER BY Prozent desc



