package td7.lab7;

import java.util.*;
import td7.graph.*;

/**
 * A class to find cycles in undirected and directed graphs
 */
public class Cycles {

	private static Graph G;

	/////////////// Cycle detection for undirected graphs

	private static Set<Vertex> visited;

	/**
	 * Returns true if the graph 'G' is cyclic
	 * false otherwise
	 */
	public static boolean hasCycle(UnDiGraph G) {
		visited = new HashSet<Vertex>();
		Cycles.G = G;

		for (Vertex v : G.vertices()){
			for (Vertex u : G.vertices()){
				if (! v.equals(u)){
					return hasCycle(u,v);
				}
			}
		}

		return false;
	}

	/**
	 * Returns true if a cycle was found by traversing
	 * the graph, coming from vertex from and going by vertex u
	 * Precondition: vertex 'from' is visited and vertex 'u' is
	 * not visited
	 */
	private static boolean hasCycle(Vertex u, Vertex from) {
		if (from==null) return false;
		if (visited.contains(from)){
			return false;
		}
		else if (u.equals(from)){
			return true;
		}
		else{
			visited.add(from);
			for (Vertex v : G.adjacents(from)){
				return hasCycle(u,v);
			}
		}

		return true;
	}

	/////////////// Cycle detection for directed graphs

	enum Status { UnDiscovered, InProgress, Completed } // status of vertex

	private static Map<Vertex,Status> vertexStatus; // to set the status of each vertex

	/**
	 * Returns true if the graph 'G' is cyclic
	 * false otherwise
	 */
	private static boolean hasCycle(DiGraph G) {
		vertexStatus = new HashMap<Vertex,Status>();
		Cycles.G = G;

		for (Vertex v : G.vertices()){
			return hasCycle(v);
		}

		return false;
	}

	/**
	 * Returns true if a cycle was found by traversing
	 * the graph from vertex u
	 * Precondition: vertex 'u' is 'UnDiscovered'
	 */
	private static boolean hasCycle(Vertex u) {
		return false;
	}


	/**
	 * Returns the status of vertex 'u'
	 */
	private static Status status(Vertex u) {
		Status s = vertexStatus.get(u);
		if ( s == null )
			return Status.UnDiscovered;
		return s;
	}

	/**
	 * Sets the status of vertex 'u' to 's'
	 */
	private static void setStatus(Vertex u, Status s) {
		vertexStatus.put(u,s);
	}

	///////////////

	public static void main(String[] s) {
		// DiGraph G = GraphReader.D1;

		UnDiGraph G = GraphReader.U1;

		System.out.println(hasCycle(GraphReader.U1));
		System.out.println(hasCycle(GraphReader.U2));
		System.out.println(hasCycle(GraphReader.U3));
		System.out.println(hasCycle(GraphReader.U4));
	}
}
