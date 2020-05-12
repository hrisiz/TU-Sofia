package com.example.demo.model;

import java.util.Date;
import java.sql.Time;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.NamedQuery;

@NamedQuery(name = "WorkDay.findByDay", query = "SELECT p FROM WorkDay p WHERE p.day=?1")
@Entity
public class WorkDay {

	private Integer user_id;

	private Date day;
	private Time start_time;
	private Time end_time;
	private Time rest_time;
	private Double salary;

	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	@Column(name="id")
	private Integer id;

	public Integer getUser_id() {
		return user_id;
	}

	public void setUser_id(Integer user_id) {
		this.user_id = user_id;
	}

	public Date getDay() {
		return day;
	}

	public void setDay(Date day) {
		this.day = day;
	}
	
	public Time getStart_time() {
		return start_time;
	}

	public void setStart_time(Time start_time) {
		this.start_time = start_time;
	}

	public Time getEnd_time() {
		return end_time;
	}

	public void setEnd_time(Time end_time) {
		this.end_time = end_time;
	}

	public Time getRest_time() {
		return rest_time;
	}

	public void setRest_time(Time rest_time) {
		this.rest_time = rest_time;
	}

	public Double getSalary() {
		return salary;
	}

	public void setSalary(Double salary) {
		this.salary = salary;
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String toString(){
	    return id + " | " + user_id + " | " + day+ " | " + start_time+ " | " + end_time+ " | " + rest_time+ " | " + salary;
	}
	
}
