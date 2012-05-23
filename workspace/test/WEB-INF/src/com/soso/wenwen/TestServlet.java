/**
 * 
 */
package com.soso.wenwen;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * @author zouw
 *
 */
public class TestServlet extends HttpServlet {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private static final String CONTENT_TYPE="text/html; charset=GBK";
	public void doGet(HttpServletRequest request, HttpServletResponse response)
	throws ServletException, IOException
	{
		response.setContentType(CONTENT_TYPE);
		PrintWriter out = response.getWriter();
		int n = 1;
		for (int i=1; i<=5; i++){
			n *= i;
		}
		out.println("<html>");
		out.println("<head><title>TestServlet</title><head>");
		out.println("<body>");
		out.println("<p>5!="+n+"</p>");
		out.println("</body></html>");
		out.close();
	}
}
