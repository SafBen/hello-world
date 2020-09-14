<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html" encoding="UTF-8"/>
  <xsl:template match="/">
    <html>
      <head>
	<title>
	  L'année et les titres de films
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
  
  <xsl:template match="FILM">
    <p>
      <xsl:choose>
        <xsl:when test="@Annee > 1986">
          <strong>
	    <xsl:value-of select="@Annee"/>
            <xsl:apply-templates select="TITRE"/>
          </strong>
	</xsl:when>
	<xsl:otherwise>
          <em>
	    <xsl:value-of select="@Annee"/>
            <xsl:apply-templates select="TITRE"/>
          </em>
	</xsl:otherwise>
      </xsl:choose>
    </p>
  </xsl:template>
  
  <xsl:template match="TITRE">
    <xsl:text> : </xsl:text>
    <xsl:value-of select="."/>
  </xsl:template>
</xsl:stylesheet>
