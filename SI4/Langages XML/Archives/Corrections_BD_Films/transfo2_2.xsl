<?xml version="1.0" encoding="UTF-8"?>
<!-- la ligne suivante doit être avant la balise xsl:stylesheet -->
<!DOCTYPE xsl:stylesheet [ <!ENTITY nbsp "&#160;"> ]>
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
	<h1>Voici la liste triée des <xsl:value-of select="count(//FILM[GENRE = 'Drame']/ROLES/ROLE)" /> acteurs des <xsl:value-of select="count(//FILM[GENRE = 'Drame'])" /> drames</h1>
	<blockquote>
	  <xsl:apply-templates select="//ROLE">
            <xsl:sort select="NOM" order="ascending" />
	  </xsl:apply-templates>
	</blockquote>
      </body>
    </html>
  </xsl:template>
  <xsl:template match="ROLE"/>
  
  <xsl:template match="ROLE[../../GENRE = 'Drame']">
		<p><strong>
			<xsl:value-of select="NOM"/>, <xsl:value-of select="PRENOM"/>
        </strong></p>
  </xsl:template>
</xsl:stylesheet>
