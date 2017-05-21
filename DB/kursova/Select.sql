2. Напишете заявка, в която демонстрирате SELECT с ограничаващо условие по избор.
Да се извадят всички хора който носят размер на дрехите L
Select Persons.name From Persons Where clothes_size='L';

3. Напишете заявка, в която използвате агрегатна функция и GROUP BY по ваш избор.
Да се извадят бройката на посетените места за всеки човек
Select Persons.clothes_size,COUNT(Persons.id) From Persons Group by clothes_size;

4. Напишете заявка, в която демонстрирате INNER и OUTER JOIN по ваш избор.
Да се извади за всяка локация колко човека са я посетили включително придружителите
Select Countries.name,Cities.name,Addresses.address,Locations.gps_cord,Locations.place_type,
(COUNT(persons_locations.id) + (Select COUNT(persons_locations_with.person_id) From persons_locations_with 
Left Join persons_locations On persons_locations_with.persons_locations_id = persons_locations.id
where persons_locations.location_id = Locations.id)) as PersonsCount From Locations 
Join Addresses On Locations.address_id = Addresses.id
Join Cities On Addresses.city_id = Cities.id 
Join Countries On Addresses.country_id = Countries.id 
Left Join persons_locations On Locations.id = persons_locations.location_id 
Group by Locations.id;

5. Напишете заявка, в която демонстрирате едновременно JOIN и агрегатна функция.
Да се извади за всеки човек броят на посетените локации(може и като придружител само да е)
Select Persons.name,(Count(persons_locations.id)+(Select Count(*) From persons_locations_with
Where Persons.id = persons_locations_with.person_id)) as LocationsCount From Persons
Left Join persons_locations on persons_locations.person_id = Persons.id
Group by Persons.id;
