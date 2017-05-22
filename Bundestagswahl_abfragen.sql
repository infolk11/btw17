-- Wertzuweisung von Variablen: Für strings- SET @variablenname = 'String';
--                              Für Integer- SET @variablenname = Zahl ;


-- PARTEIEN:



-- alle Partei-IDs + Partei-Bezeichungen
select P_ID, P_Bezeichnung from partei;


-- alle Daten einer bestimmten Partei
-- set @p = z  ||  z = Parteiname ODER Partei-ID -> es kann nach beidem gesucht werden
select * from Partei where P_Bezeichnung = @p or P_ID = @p;


--                                                                       ACHTUNG: 'P_ID' als Fremdschlüssel in direktkandidaten benötigt, Änderung von 'Name' zu 'Nachname' in direktkandidaten benötigt
-- Parteien und zugehörige Kandidaten
select P_Bezeichnung, Vorname, Nachname from direktkandidaten d, partei p 
where d.p_id = p.p_id;


-- Bestimmte Partei und zugehöriger Kandidat                             ACHTUNG: Änderung von 'Name' zu 'Nachname' in direktkandidaten benötigt
-- set @k = z  ||  z = Parteiname ODER Partei-ID -> es kann nach beidem gesucht werden     
select P_Bezeichnung, Vorname, Nachname from direktkandidaten d, partei p 
where d.p_id = p.p_id and D_ID=@k or Nachname = @k;


-- Farbe einer Partei 
-- set @f = y; || y = Parteiname ODER Partei-ID
select P_Bezeichnung, Farbe from partei where P_bezeichnung = @f or P_ID = @f;



-- KANDIDATEN:



-- ID, Vorname und Nachname aller Kandidaten                             ACHTUNG: Änderung von 'Name' zu 'Nachname' in direktkandidaten benötigt
select ID, Vorname, Nachname from Direktkandidaten;


-- Bestimmter Kandidat und zugehörige Partei                             ACHTUNG: 'P_ID' als Fremdschlüssel in direktkandidaten benötigt, Änderung von 'Name' zu 'Nachname' in direktkandidaten benötigt
-- set @pk= d || d = Kandidatennachname ODER Kandidaten-ID --> beides möglich
select vorname, nachname from direktkandidaten d 
inner join partei p on d.p_id = p.p_id where nachname=@pk or P_ID=@pk;


--                                                                       ACHTUNG: 'P_ID' als Fremdschlüssel in direktkandidaten benötigt; Änderung von 'Name' zu 'Nachname' in direktkandidaten benötigt
-- alle Kandidaten mit zugehöriger Partei (wenn vorhanden), geordnet nach Nachname (A-Z)  
select vorname, Nachname, P_Bezeichnung from direktkandidaten d, partei p
where d.p_id = p.p_id order by Nachname;

--                                                                        ACHTUNG: 'P_ID' als Fremdschlüssel in direktkandidaten benötigt; Änderung von 'Name' zu 'Nachname' in direktkandidaten benötigt
-- alle Kandidaten mit zugehöriger Partei (wenn vorhanden), geordnet nach Partei (A-Z)
select vorname, nachname, P_Bezeichnung from direktkandidaten d, partei p
where d.p_id = p.p_id order by P_Bezeichnung;



-- WAHLLOKALE:



-- Wahllokal-ID + Bezeichnung aller Wahllokale
select W_ID, W_Bezeichnung from wahllokal;


-- Adresse + Wahllokal-ID + Bezeichnung, geordnet nach Wahllokalbezeichnung (A-Z)
select W_ID, W_Bezeichnung, straße from wahllokal order by W_Bezeichnung;


-- Adresse + Wahllokal-ID + Bezeichnung eines bestimmen Wahllokals
-- set @g = f  ||  f = Wahllokal-ID ODER Wahllokalbezeichnung
select straße, W_ID, W_Bezeichnung from wahllokal where W_ID = @g or W_Bezeichnung = @g;



-- NEURUPPIN ALS BUNDESTAG:


-- Sitze aller Parteien
-- Select P_Bezeichnung as Partei, 299/(Select sum(2Anzahl))/(Select sum(2Anzahl) from 2stimme)*100 as Prozent 
-- from 2stimme 2s, partei p where 2s.P_ID = p.P_ID;



