package com.example.demo.model;

import java.util.Date;
import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.repository.CrudRepository;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

@Repository
public interface WorkDayRepository 
  extends CrudRepository<WorkDay, Integer>, JpaRepository<WorkDay, Integer> {
	public List<WorkDay> findByDay(@Param("day") Date day);
}