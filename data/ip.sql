
CREATE TABLE IF NOT EXISTS ips (
    ip_from INTEGER UNIQUE,
    ip_to INTEGER UNIQUE,
    country_code TEXT,
    country_name TEXT,
    region_name TEXT,
    city_name TEXT,
    latitude REAL,
    longitude REAL
);
