
Тема
Разработете база данни за следене на хора. Пази се информация за проследяваните хора – три имена, ЕГН, адрес, имейл, телефонен номер, семеен статус, кола, номер на обувките, размер на дрехите и всякаква друга информация. Пази се информация за често посещавани места от субектите – държава, град, адрес, GPS координати, вид на мястото (заведение, библиотека, ресторант, бар, кръчма и т.н.). Пази се и информация за точните посещения – дата, час, колко време са седели, сами ли са били, ако не с кого. 

1. Да се проектира база от данни и да се представи ER диаграма със съответни CREATE TABLE заявки за средата MySQL.

DROP DATABASE IF EXISTS Stalkers;
CREATE DATABASE Stalkers;
use Stalkers;
CREATE TABLE Persons(
	id INT PRIMARY KEY auto_increment,
	name varchar(255) NOT NULL,
	EGN varchar(10) NOT NULL unique,
	address varchar(255),
	email varchar(50) unique,
	phone varchar(10) unique,
	family_status enum('1','2'),
	car_number varchar(10) unique,
	shoes_number int,
	clothes_size char(10)
);
CREATE TABLE Countries(
	id int PRIMARY KEY auto_increment,
	name varchar(255)
);
CREATE TABLE Cities(
	id int PRIMARY KEY auto_increment,
	name varchar(255)
);

CREATE TABLE Addresses(
	id int PRIMARY KEY auto_increment,
	country_id int,
	city_id int,
	address varchar(100),
	FOREIGN KEY (country_id) REFERENCES Countries(id),
	FOREIGN KEY (city_id) REFERENCES Cities(id)
);
CREATE TABLE Locations(
	id int PRIMARY KEY auto_increment,
	address_id int,
	gps_cord varchar(255),
	place_type enum('bar','club','sport'),
	FOREIGN KEY (address_id) REFERENCES Addresses(id)
);
CREATE TABLE persons_locations(
	id int PRIMARY KEY auto_increment,
	person_id int NOT NULL,
	location_id int NOT NULL,
	stay_time TIME NOT NULL,
	FOREIGN KEY (person_id) REFERENCES Persons(id),
	FOREIGN KEY (location_id) REFERENCES Locations(id),
	UNIQUE KEY(person_id,location_id)
);

CREATE TABLE persons_locations_with(
	persons_locations_id int,
	person_id int,
	FOREIGN KEY (persons_locations_id) REFERENCES persons_locations(id),
	FOREIGN KEY (person_id) REFERENCES Persons(id)
);



Insert Into Persons values(NULL, 'Gosho', '46453198', NULL, 'hrerowe@grpiw.ngre', '0864685210', '1', 'Ca07763KS', '47', 'L');
Insert Into Persons values(NULL, 'Pesho', '46423199', NULL, 'gree@grpiw.ngre', '0864685211', '1', 'Ca07163KS', '47', 'L');
Insert Into Persons values(NULL, 'Petka', '46433197', NULL, 'wfv@grpiw.ngre', '0864685212', '1', 'Ca07743KS', '47', 'T');
Insert Into Persons values(NULL, 'Kolio', '54453196', NULL, 'greerht54@grpiw.ngre', '0864385210', '1', 'CO07453KS', '47', 'M');
Insert Into Persons values(NULL, 'Ivan', '95453194', NULL, '5yr@grpiw.ngre', '0864685216', '1', 'Ca07763MS', '47', 'M');
Insert Into Persons values(NULL, 'Maria', '56453193', NULL, '4ht@grpiw.ngre', '0864685218', '1', 'Ca07763LS', '47', 'S');
Insert Into Persons values(NULL, 'Ivanka', '01453192', NULL, 'gehn@grpiw.ngre', '0864685910', '1', 'Ca07763QS', '47', 'S');

Insert Into Countries values(NULL, 'Bulgaria');
Insert Into Countries values(NULL, 'Russia');
Insert Into Countries values(NULL, 'Germany');

Insert Into Cities values(NULL, 'Sofia');
Insert Into Cities values(NULL, 'Plovdiv');
Insert Into Cities values(NULL, 'Varna');

Insert Into Addresses values(NULL, 1, 1, 'greghjebgreo');
Insert Into Addresses values(NULL, 1, 2, 'hgrtrbgreo');
Insert Into Addresses values(NULL, 1, 3, 'ebgreo');

Insert Into Locations values(NULL, 1, '50, 2000 -20.6545', 'bar');
Insert Into Locations values(NULL, 1, '20, 5400 -10.6545', 'club');
Insert Into Locations values(NULL, 1, '30, 1000 -80.6545', 'sport');

Insert Into persons_locations values(NULL, 1, 1, '2:12:50');
Insert Into persons_locations values(NULL, 1, 2, '4:25:00');
Insert Into persons_locations values(NULL, 1, 3, '1:55:40');

Insert Into persons_locations_with values(1, 2);
Insert Into persons_locations_with values(1, 3);
Insert Into persons_locations_with values(1, 4);



