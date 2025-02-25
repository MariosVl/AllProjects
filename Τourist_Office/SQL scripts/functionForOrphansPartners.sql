-- DROP FUNCTION tourist_office.delete_orphan_partners();

CREATE OR REPLACE FUNCTION tourist_office.delete_orphan_partners()
 RETURNS trigger
 LANGUAGE plpgsql
AS $function$
BEGIN
    -- Έλεγχος αν ο partner δεν έχει καμία σύνδεση με accomondation
    IF TG_TABLE_NAME = 'accomondation' THEN
        IF NOT EXISTS (SELECT 1 FROM tourist_office.accomondation WHERE partner_id = OLD.partner_id) THEN
            DELETE FROM tourist_office.partners WHERE afm = OLD.partner_id;
        END IF;

    -- Έλεγχος αν ο partner δεν έχει καμία σύνδεση με airplanes
    ELSIF TG_TABLE_NAME = 'airplanes' THEN
        IF NOT EXISTS (SELECT 1 FROM tourist_office.airplanes WHERE partner_id = OLD.partner_id) THEN
            DELETE FROM tourist_office.partners WHERE afm = OLD.partner_id;
        END IF;

    -- Έλεγχος αν ο partner δεν έχει καμία σύνδεση με ships
    ELSIF TG_TABLE_NAME = 'ships' THEN
        IF NOT EXISTS (SELECT 1 FROM tourist_office.ships WHERE partner_id = OLD.partner_id) THEN
            DELETE FROM tourist_office.partners WHERE afm = OLD.partner_id;
        END IF;
    END IF;
    RETURN OLD;
END;
$function$
;
