<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet 
  version="1.0" 
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns="http://www.w3.org/1999/xhtml">
  <xsl:template match="/">
    <html>
    <body>
    <ul>
	<xsl:apply-templates select="//FILM"/>
	<xsl:for-each select="//NOTE">
		<xsl:sort data-type="number" select="." order="ascending"/>
		<xsl:if test="position() = 1">  
			Note Min : <xsl:value-of select="." /> pour le film <xsl:value-of select="../../TITRE" /><br />
		</xsl:if>
		<xsl:if test="position() = last()">    
			Note Max : <xsl:value-of select="." /> pour le film <xsl:value-of select="../../TITRE" /><br />
		</xsl:if>
	</xsl:for-each>  
	</ul>
    </body>
    </html>
  </xsl:template>
  
  <xsl:template match="FILM" >
    <xsl:for-each select="NOTES/NOTE">
		<xsl:sort data-type="number" select="." order="ascending"/>
		<xsl:if test="position() = 1">  
			Min de <xsl:value-of select="../../TITRE"/> : <xsl:value-of select="."/><br/>
		</xsl:if>
		<xsl:if test="position() = last()">    
			Max de <xsl:value-of select="../../TITRE"/> : <xsl:value-of select="."/><br/><br/>
		</xsl:if>
	</xsl:for-each>    
  </xsl:template>

</xsl:stylesheet>
