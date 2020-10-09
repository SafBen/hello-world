<?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">
		<html> <head> <title> Liste des titres et artistes </title> </head>
		<body>
			<h2>Liste des titres et artistes</h2>
			<table border="1">
				<tr bgcolor="#9acd32">
					<th align="left">Title</th>
					<th align="left">Artist</th>
					<xsl:apply-templates select="CATALOG/CD"> 
						<xsl:sort select="ARTIST"/>
					</xsl:apply-templates>
				</tr>
			</table>
		</body> 
	</html>
</xsl:template>

<xsl:template match="CD"> 
	<xsl:apply-templates select="ARTIST[../PRICE>10]"/> <!--> Filtre déjà fait <-->
</xsl:template>

<xsl:template match="ARTIST"> <!--> Si filtre ici il faut ajouter un autre template vide <-->
	<tr>
		<td>
			<xsl:value-of select="../TITLE"/>
		</td>
		<td><xsl:value-of select="."/></td>
	</tr>
</xsl:template>
</xsl:stylesheet>

