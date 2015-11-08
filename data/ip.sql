
CREATE TABLE IF NOT EXISTS ips (
    -- id INTEGER,
    ip_from TEXT UNIQUE,
    ip_to TEXT UNIQUE,
    country_code TEXT,
    country_name TEXT,
    region_name TEXT,
    city_name TEXT,
    latitude REAL,
    longitude REAL
    -- PRIMARY KEY (id ASC)
);
