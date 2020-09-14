<?xml version="1.0" encoding="UTF-8"?>
<!-- la ligne suivante doit être avant la balise xsl:stylesheet -->
<!DOCTYPE xsl:stylesheet [ <!ENTITY nbsp "&#160;"> ]>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html" encoding="UTF-8"/>
  
  <xsl:template match="/">
    <html>
      <head>
	<title>
	  L'année et les titres de films en HTML via XML
	</title>
      </head>
      <body>
	<h1>Voici la liste des <xsl:value-of select="count(//FILM)" /> films </h1>
	<blockquote>
	  <xsl:apply-templates select="//FILM">
            <xsl:sort select="@Annee" order="descending" />
	  </xsl:apply-templates>
	</blockquote>
      </body>
    </html>
  </xsl:template>
  
  <xsl:template match="FILM[@Annee &gt; 1986]">
    <p>
	<strong>
	<xsl:value-of select="@Annee"/> <xsl:text> : </xsl:text>
	<xsl:value-of select="TITRE"/>
	</strong>
    </p>
  </xsl:template>

  <xsl:template match="FILM">
    <p>
    <em>
	<xsl:value-of select="@Annee"/> <xsl:text> : </xsl:text>
	<xsl:value-of select="TITRE"/>
    </em>
    </p>
  </xsl:template>
  
</xsl:stylesheet>
