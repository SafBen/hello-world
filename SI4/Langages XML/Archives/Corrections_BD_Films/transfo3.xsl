<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE xsl:stylesheet [ <!ENTITY nbsp "&#160;"> ]>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="xml" encoding="UTF-8"/>
  
  <xsl:template match="/">
	<xsl:element name="ARTISTES">
	  <xsl:apply-templates select="//ARTISTE">
            <xsl:sort select="ACTNOM" order="ascending" />
	  </xsl:apply-templates>
	</xsl:element>  
  </xsl:template>
  
  <xsl:template match="ARTISTE">
	<xsl:copy>
			<xsl:attribute name="naissance">
				<xsl:value-of select="ANNEENAISS" />
			</xsl:attribute>
            <xsl:apply-templates select="ACTNOM"/>
	        <xsl:apply-templates select="ACTPNOM"/>
	</xsl:copy>
  </xsl:template>
  
  <xsl:template match="ACTNOM">
	<xsl:copy>
	<xsl:apply-templates/>
	</xsl:copy>
  </xsl:template>
  
  <xsl:template match="ACTPNOM">
	<xsl:copy>
	<xsl:apply-templates/>
	</xsl:copy>
  </xsl:template>
</xsl:stylesheet>
