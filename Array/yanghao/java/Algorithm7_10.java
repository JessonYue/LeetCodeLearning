package com.example.servlet;

import java.util.UUID;

public class Algorithm7_10 {
	
	public static String getToken() {
		return UUID.randomUUID().toString();
	}
}
