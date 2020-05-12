package com.example.demo.controller;

import java.awt.PageAttributes.MediaType;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.example.demo.model.User;
import com.example.demo.model.UserRepository;
import com.example.demo.service.UserService;


@Controller
@RequestMapping(path="/user")
public class UserController {
	private UserService user_service = new UserService();

	@Autowired
	private UserRepository userRepository;
	
	@PostMapping(value="/addUser")
	@ResponseBody
	public User addUser(@RequestBody User input_user) {	
		System.out.println("Hello11111");
		User n =  user_service.addUser(input_user);
	    userRepository.save(n);
	    return n;
	}	

	@GetMapping(value="/getUser/{id}")
	@ResponseBody
	public User addUser(@PathVariable("id") Integer id, Model model) {
		Optional<User> result = userRepository.findById(id);
		return result.get();
	}
	
	@DeleteMapping(value="/deleteUser/{id}")
	@ResponseBody
	public Boolean deleteUser(@PathVariable("id") Integer id) {
		userRepository.deleteById(id);
		return true;
	}

}
