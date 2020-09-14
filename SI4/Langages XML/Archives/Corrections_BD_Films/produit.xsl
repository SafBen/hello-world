<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method = "text"/>
  
  <xsl:template match="/">	
    <xsl:call-template name = "total" >
      <xsl:with-param name="noeuds" select="//produit"></xsl:with-param>
      <xsl:with-param name="s_total" select="0"></xsl:with-param>
    </xsl:call-template>
  </xsl:template>
	
  <xsl:template name="total">
    <xsl:param name="noeuds" />
    <xsl:param name="s_total" />
    
		
    <xsl:choose>
      <xsl:when test="$noeuds[position()>1]">
	<xsl:call-template name = "total" >
	  <xsl:with-param name="noeuds" select="$noeuds[position()>1]"></xsl:with-param>
	  <xsl:with-param name="s_total" select="$s_total+($noeuds[1]/nb*$noeuds[1]/prix)"></xsl:with-param>
	</xsl:call-template>
      </xsl:when>
      
      <xsl:otherwise>
	total : <xsl:value-of select="$s_total+($noeuds[1]/nb*$noeuds[1]/prix)" />
      </xsl:otherwise>
    </xsl:choose>
    
  </xsl:template>
  
</xsl:stylesheet>

