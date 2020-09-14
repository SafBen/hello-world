<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="xml" encoding="UTF-8"/>
  

  <xsl:template match="FILMS">
    <xsl:element name="{name(.)}">
		<xsl:element name="INCOMPLETS">
			<xsl:apply-templates select="FILM[not(RESUME/text())]"/>
		</xsl:element>
		<xsl:element name="COMPLETS">
			<xsl:apply-templates select="FILM[RESUME/text()]"/>
		</xsl:element>
    </xsl:element>
  </xsl:template>

  <xsl:template match="FILM">
		<xsl:element name="FILM">
			<xsl:value-of select="TITRE"/>
		</xsl:element>
  </xsl:template>
  
    <xsl:template match="*"/>
  
    
</xsl:stylesheet>
