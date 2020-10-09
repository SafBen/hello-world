<?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">
		<html> <head> <title> cd_catalog_bis </title> </head>
		<body>
			<h2>CD Collection BIS</h2>
			<table border="1">
				<tr bgcolor="#ff0000">
					<th align="left">Title</th>
					<th align="left">Artist</th>
					<xsl:apply-templates/> 
				</tr>
			</table>
		</body> 
	</html>
</xsl:template>

<xsl:template match="CD"> 
	<xsl:apply-templates select="TITLE"/> 
</xsl:template>

<xsl:template match="TITLE"> 
	<tr>
		<td>
			<xsl:value-of select="."/>
		</td>
		<xsl:apply-templates select="../ARTIST"/>
	</tr>
</xsl:template>

<xsl:template match="ARTIST"> 
	<td><xsl:value-of select="."/></td>
</xsl:template>

</xsl:stylesheet>

