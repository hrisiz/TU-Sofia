package com.example.demo.service;

import org.springframework.stereotype.Service;

import com.example.demo.model.User;
@Service
public class UserService {

	
	public User addUser(User input_user)
	{
		User n = null;
		if(null != input_user.getId())
		{
			n = new User();  // GetUser by ID userRepository.getById(input_user.getId())
			if(null != input_user.getUsername())
			{
				n.setUsername(input_user.getUsername());
			}
			
			if(null != input_user.getPassword())
			{
				n.setPassword(input_user.getPassword());
			}
			
			if(null != input_user.getName())
			{
				n.setName(input_user.getName());
			}
			
			if(null != input_user.getEmail())
			{
				n.setEmail(input_user.getEmail());
			}
			
			if(null != input_user.getSalery())
			{
				n.setSalery(input_user.getSalery());
			}
		}
		else
		{
			n = input_user;
		}

		return n;	
	}
}