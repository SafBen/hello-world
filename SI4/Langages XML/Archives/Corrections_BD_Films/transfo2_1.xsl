<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html" encoding="UTF-8"/>
  <xsl:template match="/">
    <html>
      <head>
	<title>
	  Les acteurs de drames
	</title>
      </head>
      <body>
	<h1>Voici la liste triée des <xsl:value-of select="count(FILMS/FILM[GENRE = 'Drame']/ROLES/ROLE)" /> acteurs des <xsl:value-of select="count(//FILM[GENRE = 'Drame'])" /> drames</h1>
<blockquote>
	  <xsl:apply-templates select="FILMS/FILM[GENRE = 'Drame']/ROLES/ROLE">
            <xsl:sort select="NOM" order="ascending" />
	  </xsl:apply-templates>
	</blockquote>
      </body>
    </html>
  </xsl:template> 
  <xsl:template match="ROLE">
            <p><strong>
    <xsl:value-of select="NOM"/>, <xsl:value-of select="PRENOM"/>
	          </strong></p>

  </xsl:template>
</xsl:stylesheet>
