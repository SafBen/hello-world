package addressbook.v3t;

/**
 * Thrown if a key is already in use.
 * @author <a href="mailto:sander@polytech.unice.fr">Peter Sander</a>
 * @version $Id$
 */
@SuppressWarnings("serial")
class DuplicateKeyException extends RuntimeException {
	DuplicateKeyException(String key) {
		super(key);
	}
	
	@Override
	public String toString() {
		return "Key " + getMessage() + " already in use.";
	}
}
