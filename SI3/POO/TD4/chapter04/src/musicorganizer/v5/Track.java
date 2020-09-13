package musicorganizer.v5;

/**
 * Store the details of a music track,
 * such as the artist, title, and file name.
 * 
 * @author David J. Barnes and Michael Kölling
 * @version 2016.02.29
 */
class Track {
    // The artist.
    private final String artist;
    // The track's title.
    private final String title;
    // Where the track is stored.
    private final String filename;
    
    /**
     * Constructor for objects of class Track.
     * @param artist The track's artist.
     * @param title The track's title.
     * @param filename The track file. 
     */
    private Track(String artist, String title, String filename) {
        setDetails(artist, title, filename);
    }
    
    /**
     * Constructor for objects of class Track.
     * It is assumed that the file name cannot be
     * decoded to extract artist and title details.
     * @param filename The track file. 
     */
    private Track(String filename) {
        setDetails("unknown", "unknown", filename);
    }
    
    /**
     * Return the artist.
     * @return The artist.
     */
    private String getArtist() {
        return artist;
    }
    
    /**
     * Return the title.
     * @return The title.
     */
    private String getTitle() {
        return title;
    }
    
    /**
     * Return the file name.
     * @return The file name.
     */
    private String getFilename() {
        return filename;
    }
        
    /**
     * Return details of the track: artist, title and file name.
     * @return The track's details.
     */
    private String getDetails() {
        return artist + ": " + title + "  (file: " + filename + ")";
    }
    
    /**
     * Set details of the track.
     * @param artist The track's artist.
     * @param title The track's title.
     * @param filename The track file. 
     */
    private void setDetails(String artist, String title, String filename) {
        this.artist = artist;
        this.title = title;
        this.filename = filename;
    }
    
}

