<?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">
		<Artistes>
			<xsl:apply-templates/> 
		</Artistes>
	</xsl:template>

	<xsl:template match="CD"> 
		<xsl:apply-templates select="ARTIST[../COUNTRY='UK']"/>
	</xsl:template>


	<xsl:template match="ARTIST">
		<Artiste><Nom>
			<xsl:value-of select="."/>
		</Nom>
		<xsl:apply-templates select="../COUNTRY"/>
		</Artiste>
	</xsl:template>

	<xsl:template match="COUNTRY">
		<Pays>
			<xsl:value-of select="."/>
		</Pays>
	</xsl:template>
</xsl:stylesheet>

