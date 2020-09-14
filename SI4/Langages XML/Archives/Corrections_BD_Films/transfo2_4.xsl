<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html" encoding="UTF-8"/>
<xsl:template match="/">
	<html> <body>
		<h1>Voici la liste triée des <xsl:value-of select="count(FILMS/FILM[GENRE = 'Drame']/ROLES/ROLE)"/>  
		acteurs des <xsl:value-of select="count(FILMS/FILM[GENRE = 'Drame'])"/> drames</h1>
			<xsl:for-each select="FILMS/FILM[GENRE = 'Drame']/ROLES/ROLE">
				<xsl:sort select="NOM" />
					<p>
					<xsl:value-of select="NOM"/>, <xsl:value-of select="PRENOM"/>
					</p>
			</xsl:for-each>
	</body></html>
</xsl:template>
</xsl:stylesheet>