<?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">
		<html> <head> <title> cd_catalog </title> </head>
		<body>
			<h2>CD Catalog</h2>
			<xsl:apply-templates/> 
		</body> 
	</html>
</xsl:template>

<xsl:template match="CD"> 
	<p>
		<xsl:apply-templates select="TITLE"/> 
		<xsl:apply-templates select="ARTIST"/>
		<xsl:apply-templates select="PRICE"/>
	</p> </xsl:template>

	<xsl:template match="TITLE"> Title: 
		<span style="color:#ff0000"> <xsl:value-of select="."/></span> 
		<br />
	</xsl:template>

	<xsl:template match="ARTIST"> Artist: 
		<span style="color:#00ff00"> <xsl:value-of select="."/></span>
		<br />
	</xsl:template>

	<xsl:template match="PRICE"> Price:
		<span style="color:#0000ff"> <xsl:value-of select="."/></span>
		<br />
	</xsl:template>
</xsl:stylesheet>

