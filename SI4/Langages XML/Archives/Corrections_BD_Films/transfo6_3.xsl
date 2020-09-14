<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="xml" encoding="UTF-8"/>
  

  <xsl:template match="FILMS">
    <xsl:element name="{name(.)}">
		<xsl:element name="INCOMPLETS">
			<xsl:apply-templates select="FILM" mode="oui"/>
		</xsl:element>
		<xsl:element name="COMPLETS">
			<xsl:apply-templates select="FILM" mode="non"/>
		</xsl:element>
    </xsl:element>
  </xsl:template>

  <xsl:template match="FILM" mode="oui">
	<xsl:if test = "not(RESUME/text())">
		<xsl:element name="FILM">
			<xsl:value-of select="TITRE"/>
		</xsl:element>
	</xsl:if>
  </xsl:template>

  <xsl:template match="FILM" mode="non">
	<xsl:if test = "RESUME/text()">
		<xsl:element name="FILM">
			<xsl:value-of select="TITRE"/>
		</xsl:element>
	</xsl:if>
  </xsl:template>
  
    <xsl:template match="*"/>
  
    
</xsl:stylesheet>
