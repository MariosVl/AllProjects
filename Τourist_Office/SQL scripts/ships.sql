-- tourist_office.ships definition

-- Drop table

-- DROP TABLE tourist_office.ships;

CREATE TABLE tourist_office.ships (
	shipid varchar(100) NOT NULL,
	partner_id varchar(10) NOT NULL,
	existcabin bool NOT NULL,
	port varchar(80) NOT NULL,
	hasauto bool NOT NULL,
	permanimal bool NOT NULL,
	"cost" numeric NOT NULL,
	capacity int4 NOT NULL,
	CONSTRAINT ships_pkey PRIMARY KEY (shipid),
	CONSTRAINT ships_partner_id_fkey FOREIGN KEY (partner_id) REFERENCES tourist_office.partners(afm) ON DELETE CASCADE
);

-- Table Triggers

create trigger after_delete_ships after
delete
    on
    tourist_office.ships for each row execute function tourist_office.delete_orphan_partners();