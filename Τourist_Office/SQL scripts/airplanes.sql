-- tourist_office.airplanes definition

-- Drop table

-- DROP TABLE tourist_office.airplanes;

CREATE TABLE tourist_office.airplanes (
	airid varchar(100) NOT NULL,
	partner_id varchar(10) NOT NULL,
	hasbuis bool NOT NULL,
	airport varchar(80) NOT NULL,
	overweight bool NOT NULL,
	"cost" numeric NOT NULL,
	permanimal bool NOT NULL,
	capacity int4 NOT NULL,
	CONSTRAINT airplanes_pkey PRIMARY KEY (airid),
	CONSTRAINT airplanes_partner_id_fkey FOREIGN KEY (partner_id) REFERENCES tourist_office.partners(afm) ON DELETE CASCADE
);

-- Table Triggers

create trigger after_delete_airplanes after
delete
    on
    tourist_office.airplanes for each row execute function tourist_office.delete_orphan_partners();