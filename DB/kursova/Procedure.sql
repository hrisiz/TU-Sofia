6. Създайте процедура, в която демонстрирате използване на курсор.
Да се изпишат имената на следените хора.
use Stalkers;
drop procedure if exists  CursorProcedure;
delimiter |
create procedure CursorProcedure()
begin
	declare finished int;
	declare current_name varchar(255);
	declare the_cursor CURSOR for
	Select distinct Persons.name From persons_locations Join Persons on Persons.id=persons_locations.person_id;
	
	
	declare continue handler FOR NOT FOUND set finished = 1;
	set finished = 0;
	OPEN the_cursor;
	coach_loop: while( finished = 0)
	DO
	FETCH the_cursor INTO current_name;
	       IF(finished = 1)
	       THEN 
	       	LEAVE coach_loop;
	       END IF;	
	       Select current_name;
	end while;
	CLOSE the_cursor;
	SET finished = 0;
	SELECT 'Finished!';
end;
|
delimiter ;

call CursorProcedure();
