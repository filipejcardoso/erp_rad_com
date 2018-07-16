object FSubcategoriasDAO: TFSubcategoriasDAO
  OldCreateOrder = False
  Height = 534
  Width = 580
  object RESTRequest: TRESTRequest
    Client = RESTClient
    Params = <
      item
        Kind = pkURLSEGMENT
        name = 'ID'
        Options = [poAutoCreated]
      end>
    Resource = 'produtos/{ID}'
    Response = RESTResponse
    SynchronizedEvents = False
    Left = 40
    Top = 80
  end
  object RESTResponse: TRESTResponse
    Left = 40
    Top = 118
  end
  object RESTClient: TRESTClient
    BaseURL = 'http://api.com/api/v1'
    Params = <>
    HandleRedirects = True
    Left = 40
    Top = 32
  end
end
