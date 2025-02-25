-- tourist_office.accomondation definition

-- Drop table

-- DROP TABLE tourist_office.accomondation;

CREATE TABLE tourist_office.accomondation (
	hotel_id varchar(100) NOT NULL,
	totalbed int4 NOT NULL,
	price numeric NOT NULL,
	launch varchar(30) NOT NULL,
	partner_id varchar(10) NOT NULL,
	permanimal bool NOT NULL,
	image bytea NOT NULL,
	disableentrance bool NOT NULL,
	hasac bool NOT NULL,
	haswifi bool NOT NULL,
	haschildroom bool NOT NULL,
	CONSTRAINT accomondation_pkey PRIMARY KEY (hotel_id)
    CONSTRAINT accomondation_partner_id_fkey FOREIGN KEY (partner_id) REFERENCES tourist_office.partners(afm) ON DELETE CASCADE
);

-- Table Triggers

create trigger after_delete_accomondation after
delete
    on
    tourist_office.accomondation for each row execute function tourist_office.delete_orphan_partners();