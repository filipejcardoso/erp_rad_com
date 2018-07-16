object FContasReceber: TFContasReceber
  Left = 0
  Top = 0
  Caption = 'Financeiro - Contas a Receber'
  ClientHeight = 649
  ClientWidth = 1308
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 18
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 18
  object PageControlPrincipal: TPageControl
    Left = 0
    Top = 0
    Width = 1308
    Height = 649
    ActivePage = TabArquivados
    Align = alClient
    TabOrder = 0
    OnChange = PageControlPrincipalChange
    object TabPendentes: TTabSheet
      Caption = 'Pendentes'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object PanelPendentes: TPanel
        Left = 0
        Top = 129
        Width = 1300
        Height = 487
        Align = alClient
        Color = clMenuBar
        ParentBackground = False
        TabOrder = 0
        object PanelPendentesFixo: TPanel
          Left = 17
          Top = 20
          Width = 624
          Height = 435
          Color = clWhite
          ParentBackground = False
          TabOrder = 0
          object GridPendentes: TStringGrid
            Left = 1
            Top = 137
            Width = 622
            Height = 297
            Align = alClient
            TabOrder = 0
            OnDrawCell = GridPendentesDrawCell
            OnSelectCell = GridPendentesSelectCell
            ColWidths = (
              64
              64
              64
              64
              64)
            RowHeights = (
              24
              24
              24
              24
              24)
          end
          object PanelPendentesFiltro: TPanel
            Left = 1
            Top = 1
            Width = 622
            Height = 136
            Align = alTop
            Color = 5395281
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clGradientInactiveCaption
            Font.Height = 18
            Font.Name = 'Calibri'
            Font.Style = []
            ParentBackground = False
            ParentFont = False
            TabOrder = 1
            object EditBuscaPendentes: TEdit
              Left = 22
              Top = 80
              Width = 435
              Height = 26
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = 18
              Font.Name = 'Calibri'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
            end
            object ButtonFiltrarPendentes: TButton
              Left = 479
              Top = 80
              Width = 130
              Height = 25
              Caption = 'FILTRAR'
              Default = True
              TabOrder = 1
              OnClick = ButtonFiltrarPendentesClick
            end
            object GroupBox1: TGroupBox
              Left = 22
              Top = 9
              Width = 587
              Height = 58
              Caption = 'OP'#199#195'O DE CLIENTE'
              Color = cl3DDkShadow
              ParentBackground = False
              ParentColor = False
              TabOrder = 2
              object RadioSimplesPendentes: TRadioButton
                Left = 25
                Top = 27
                Width = 136
                Height = 17
                Caption = 'CLIENTE SIMPLES'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clSilver
                Font.Height = 18
                Font.Name = 'Calibri'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnClick = RadioSimplesPendentesClick
              end
              object RadioIndicacaoPendentes: TRadioButton
                Left = 175
                Top = 27
                Width = 178
                Height = 17
                Caption = 'CLIENTE INDICA'#199#213'ES'
                Color = clSilver
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clSilver
                Font.Height = 18
                Font.Name = 'Calibri'
                Font.Style = []
                ParentColor = False
                ParentFont = False
                TabOrder = 1
                OnClick = RadioIndicacaoPendentesClick
              end
              object CheckConsumidorPendentes: TCheckBox
                Left = 354
                Top = 27
                Width = 111
                Height = 17
                Caption = 'CONSUMIDOR'
                TabOrder = 2
              end
            end
          end
        end
        object PanelPendentesVariavel: TPanel
          Left = 664
          Top = 20
          Width = 617
          Height = 434
          Color = clWhite
          ParentBackground = False
          TabOrder = 1
          object GridPendentesDetalhada: TStringGrid
            Left = 1
            Top = 1
            Width = 615
            Height = 279
            Align = alClient
            TabOrder = 0
            OnDrawCell = GridPendentesDetalhadaDrawCell
            OnMouseDown = GridPendentesDetalhadaMouseDown
            OnSelectCell = GridPendentesDetalhadaSelectCell
            ColWidths = (
              64
              64
              64
              64
              64)
            RowHeights = (
              24
              24
              24
              24
              24)
          end
          object PanelPendentesOpcoes: TPanel
            Left = 1
            Top = 280
            Width = 615
            Height = 153
            Align = alBottom
            Color = 5395281
            ParentBackground = False
            TabOrder = 1
            object Label5: TLabel
              Left = 28
              Top = 39
              Width = 159
              Height = 18
              Caption = 'VALOR SELECIONADO (R$)'
              Color = 15790835
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clSilver
              Font.Height = 18
              Font.Name = 'Calibri'
              Font.Style = []
              ParentColor = False
              ParentFont = False
            end
            object Button2: TButton
              Left = 456
              Top = 58
              Width = 161
              Height = 25
              Caption = 'IMPRIMIR'
              TabOrder = 0
              OnClick = Button2Click
            end
            object EditPendentesSelecionado: TEdit
              Left = 28
              Top = 63
              Width = 225
              Height = 48
              Color = 15790835
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = 40
              Font.Name = 'Calibri'
              Font.Style = []
              ParentFont = False
              ReadOnly = True
              TabOrder = 1
            end
            object Button3: TButton
              Left = 272
              Top = 89
              Width = 161
              Height = 25
              Caption = 'EXPORTAR .TXT NFe'
              TabOrder = 2
              OnClick = Button3Click
            end
            object Button4: TButton
              Left = 272
              Top = 58
              Width = 161
              Height = 25
              Caption = 'REALIZAR FECHAMENTO'
              TabOrder = 3
              OnClick = Button4Click
            end
            object Button5: TButton
              Left = 456
              Top = 89
              Width = 161
              Height = 25
              Caption = 'ARQUIVAR'
              TabOrder = 4
              OnClick = Button5Click
            end
          end
        end
      end
      object PanelTopoPendentes: TPanel
        Left = 0
        Top = 0
        Width = 1300
        Height = 129
        Align = alTop
        Color = 5395281
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGradientInactiveCaption
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 1
        object LabelCabecalhoEmpresaPendentes: TLabel
          Left = 40
          Top = 37
          Width = 1065
          Height = 40
          Caption = 
            '[CONTAS '#192' RECEBER - PENDETES] ELETROBIDU COMERCIAL EL'#201'TRICA LTDA' +
            ' ME'
          Color = 432001
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 3198613
          Font.Height = 40
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
        end
        object LabelCabecalhoAppPendentes: TLabel
          Left = 40
          Top = 83
          Width = 266
          Height = 20
          Caption = 'MIP VENDAS E CONTROLE DE ESTOQUE'
          Color = 15790835
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 15790835
          Font.Height = 20
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
        end
      end
    end
    object TabFechamentos: TTabSheet
      Caption = 'Fechamentos'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object PanelTopoFechamentos: TPanel
        Left = 0
        Top = 0
        Width = 1300
        Height = 129
        Align = alTop
        Color = 5395281
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGradientInactiveCaption
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 0
        object LabelCabecalhoEmpresaFechamentos: TLabel
          Left = 40
          Top = 37
          Width = 1133
          Height = 40
          Caption = 
            '[CONTAS '#192' RECEBER - FECHAMENTOS] ELETROBIDU COMERCIAL EL'#201'TRICA L' +
            'TDA ME'
          Color = 432001
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clSkyBlue
          Font.Height = 40
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
        end
        object LabelCabecalhoAppFechamentos: TLabel
          Left = 40
          Top = 83
          Width = 266
          Height = 20
          Caption = 'MIP VENDAS E CONTROLE DE ESTOQUE'
          Color = 15790835
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 15790835
          Font.Height = 20
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
        end
      end
      object PanelFechamentos: TPanel
        Left = 0
        Top = 129
        Width = 1300
        Height = 487
        Align = alClient
        Color = clMenuBar
        ParentBackground = False
        TabOrder = 1
        object PanelFechamentosFixo: TPanel
          Left = 39
          Top = 20
          Width = 624
          Height = 435
          Color = clWhite
          ParentBackground = False
          TabOrder = 0
          object GridFechamentos: TStringGrid
            Left = 1
            Top = 137
            Width = 622
            Height = 297
            Align = alClient
            TabOrder = 0
            OnDrawCell = GridFechamentosDrawCell
            OnSelectCell = GridFechamentosSelectCell
            ColWidths = (
              64
              64
              64
              64
              64)
            RowHeights = (
              24
              24
              24
              24
              24)
          end
          object Panel4: TPanel
            Left = 1
            Top = 1
            Width = 622
            Height = 136
            Align = alTop
            Color = 5395281
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clGradientInactiveCaption
            Font.Height = 18
            Font.Name = 'Calibri'
            Font.Style = []
            ParentBackground = False
            ParentFont = False
            TabOrder = 1
            object EditBuscaFechamentos: TEdit
              Left = 22
              Top = 80
              Width = 435
              Height = 26
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = 18
              Font.Name = 'Calibri'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
            end
            object ButtonFiltrarFechamentos: TButton
              Left = 479
              Top = 80
              Width = 130
              Height = 25
              Caption = 'FILTRAR'
              Default = True
              TabOrder = 1
              OnClick = ButtonFiltrarFechamentosClick
            end
            object GroupBox2: TGroupBox
              Left = 22
              Top = 9
              Width = 587
              Height = 58
              Caption = 'OP'#199#195'O DE CLIENTE'
              Color = cl3DDkShadow
              ParentBackground = False
              ParentColor = False
              TabOrder = 2
              object RadioSimplesFechamentos: TRadioButton
                Left = 25
                Top = 27
                Width = 136
                Height = 17
                Caption = 'CLIENTE SIMPLES'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clSilver
                Font.Height = 18
                Font.Name = 'Calibri'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
              end
              object RadioIndicacaoFechamentos: TRadioButton
                Left = 175
                Top = 27
                Width = 178
                Height = 17
                Caption = 'CLIENTE INDICA'#199#213'ES'
                Color = clSilver
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clSilver
                Font.Height = 18
                Font.Name = 'Calibri'
                Font.Style = []
                ParentColor = False
                ParentFont = False
                TabOrder = 1
              end
              object CheckConsumidorFechamentos: TCheckBox
                Left = 359
                Top = 27
                Width = 111
                Height = 17
                Caption = 'CONSUMIDOR'
                TabOrder = 2
              end
            end
          end
        end
        object PanelFechamentosVariavel: TPanel
          Left = 664
          Top = 20
          Width = 601
          Height = 434
          Color = 5395281
          ParentBackground = False
          TabOrder = 1
          object Panel6: TPanel
            Left = 1
            Top = 1
            Width = 599
            Height = 183
            Align = alClient
            TabOrder = 0
            object GridFechamentosDetalhada: TStringGrid
              Left = 1
              Top = 1
              Width = 597
              Height = 181
              Align = alClient
              TabOrder = 0
              OnDrawCell = GridFechamentosDetalhadaDrawCell
              OnSelectCell = GridFechamentosDetalhadaSelectCell
              ColWidths = (
                64
                64
                64
                64
                64)
              RowHeights = (
                24
                24
                24
                24
                24)
            end
          end
          object Panel1: TPanel
            Left = 1
            Top = 184
            Width = 599
            Height = 249
            Align = alBottom
            TabOrder = 1
            object PageControlFechamentos: TPageControl
              Left = 1
              Top = 33
              Width = 431
              Height = 215
              ActivePage = Parcelas
              Align = alClient
              TabOrder = 0
              object Parcelas: TTabSheet
                Caption = 'Parcelas'
                ExplicitLeft = 0
                ExplicitTop = 0
                ExplicitWidth = 0
                ExplicitHeight = 0
                object GridFechamentosParcelas: TStringGrid
                  Left = 0
                  Top = 0
                  Width = 423
                  Height = 182
                  Align = alClient
                  TabOrder = 0
                  OnDrawCell = GridFechamentosParcelasDrawCell
                  OnSelectCell = GridFechamentosParcelasSelectCell
                  ColWidths = (
                    64
                    64
                    64
                    64
                    64)
                  RowHeights = (
                    24
                    24
                    24
                    24
                    24)
                end
              end
              object Pedidos: TTabSheet
                Caption = 'Pedidos'
                ImageIndex = 1
                ExplicitLeft = 0
                ExplicitTop = 0
                ExplicitWidth = 0
                ExplicitHeight = 0
                object GridFechamentosPedidos: TStringGrid
                  Left = 0
                  Top = 0
                  Width = 423
                  Height = 182
                  Align = alClient
                  TabOrder = 0
                  OnDrawCell = GridFechamentosPedidosDrawCell
                  OnMouseDown = GridFechamentosPedidosMouseDown
                  OnSelectCell = GridFechamentosPedidosSelectCell
                  ColWidths = (
                    64
                    64
                    64
                    64
                    64)
                  RowHeights = (
                    24
                    24
                    24
                    24
                    24)
                end
              end
            end
            object Panel7: TPanel
              Left = 432
              Top = 33
              Width = 166
              Height = 215
              Align = alRight
              TabOrder = 1
              object Label4: TLabel
                Left = 20
                Top = 25
                Width = 124
                Height = 20
                Caption = 'MENU DE OP'#199#213'ES'
                Color = 15790835
                Font.Charset = DEFAULT_CHARSET
                Font.Color = 15790835
                Font.Height = 20
                Font.Name = 'Calibri'
                Font.Style = [fsBold]
                ParentColor = False
                ParentFont = False
              end
              object Button6: TButton
                Left = 15
                Top = 52
                Width = 137
                Height = 25
                Caption = 'FINALIZAR'
                TabOrder = 0
                OnClick = Button6Click
              end
              object Button8: TButton
                Left = 15
                Top = 130
                Width = 137
                Height = 25
                Caption = 'IMPRIMIR'
                TabOrder = 1
                OnClick = Button8Click
              end
              object Button9: TButton
                Left = 15
                Top = 170
                Width = 137
                Height = 25
                Caption = 'ARQUIVAR'
                TabOrder = 2
                OnClick = Button9Click
              end
              object Button10: TButton
                Left = 15
                Top = 91
                Width = 137
                Height = 25
                Caption = 'EXPORTAR .TXT NFe'
                TabOrder = 3
                OnClick = Button10Click
              end
            end
            object Panel2: TPanel
              Left = 1
              Top = 1
              Width = 597
              Height = 32
              Align = alTop
              TabOrder = 2
            end
          end
        end
      end
    end
    object TabArquivados: TTabSheet
      Caption = 'Arquivados'
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object PanelArquivadosTopo: TPanel
        Left = 0
        Top = 0
        Width = 1300
        Height = 129
        Align = alTop
        Color = 5395281
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGradientInactiveCaption
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 0
        object LabelCabecalhoEmpresaArquivados: TLabel
          Left = 40
          Top = 37
          Width = 1114
          Height = 40
          Caption = 
            '[CONTAS '#192' RECEBER - ARQUIVADOS] ELETROBIDU COMERCIAL EL'#201'TRICA LT' +
            'DA ME'
          Color = 432001
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 9869039
          Font.Height = 40
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
        end
        object LabelCabecalhoAppArquivados: TLabel
          Left = 40
          Top = 83
          Width = 266
          Height = 20
          Caption = 'MIP VENDAS E CONTROLE DE ESTOQUE'
          Color = 15790835
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 15790835
          Font.Height = 20
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
        end
      end
      object PanelArquivados: TPanel
        Left = 0
        Top = 129
        Width = 1300
        Height = 487
        Align = alClient
        Color = clMenuBar
        ParentBackground = False
        TabOrder = 1
        object PanelArquivadosFixo: TPanel
          Left = 17
          Top = 20
          Width = 624
          Height = 435
          Color = clWhite
          ParentBackground = False
          TabOrder = 0
          object GridArquivados: TStringGrid
            Left = 1
            Top = 137
            Width = 622
            Height = 297
            Align = alClient
            TabOrder = 0
            OnDrawCell = GridArquivadosDrawCell
            OnSelectCell = GridArquivadosSelectCell
            ColWidths = (
              64
              64
              64
              64
              64)
            RowHeights = (
              24
              24
              24
              24
              24)
          end
          object Panel9: TPanel
            Left = 1
            Top = 1
            Width = 622
            Height = 136
            Align = alTop
            Color = 5395281
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clGradientInactiveCaption
            Font.Height = 18
            Font.Name = 'Calibri'
            Font.Style = []
            ParentBackground = False
            ParentFont = False
            TabOrder = 1
            object EditBuscaArquivados: TEdit
              Left = 22
              Top = 80
              Width = 435
              Height = 26
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = 18
              Font.Name = 'Calibri'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
            end
            object Button1: TButton
              Left = 479
              Top = 80
              Width = 130
              Height = 25
              Caption = 'FILTRAR'
              Default = True
              TabOrder = 1
              OnClick = Button1Click
            end
            object GroupBox3: TGroupBox
              Left = 22
              Top = 9
              Width = 587
              Height = 58
              Caption = 'OP'#199#195'O DE CLIENTE'
              Color = cl3DDkShadow
              ParentBackground = False
              ParentColor = False
              TabOrder = 2
              object RadioSimplesArquivados: TRadioButton
                Left = 25
                Top = 27
                Width = 136
                Height = 17
                Caption = 'CLIENTE SIMPLES'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clSilver
                Font.Height = 18
                Font.Name = 'Calibri'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
              end
              object RadioIndicacaoArquivados: TRadioButton
                Left = 175
                Top = 27
                Width = 178
                Height = 17
                Caption = 'CLIENTE INDICA'#199#213'ES'
                Color = clSilver
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clSilver
                Font.Height = 18
                Font.Name = 'Calibri'
                Font.Style = []
                ParentColor = False
                ParentFont = False
                TabOrder = 1
              end
              object CheckConsumidorArquivados: TCheckBox
                Left = 359
                Top = 27
                Width = 111
                Height = 17
                Caption = 'CONSUMIDOR'
                TabOrder = 2
              end
            end
          end
        end
        object PanelArquivadosVariavel: TPanel
          Left = 664
          Top = 20
          Width = 617
          Height = 434
          Color = clWhite
          ParentBackground = False
          TabOrder = 1
          object GridArquivadosDetalhada: TStringGrid
            Left = 1
            Top = 1
            Width = 615
            Height = 279
            Align = alClient
            TabOrder = 0
            OnDrawCell = GridArquivadosDetalhadaDrawCell
            OnMouseDown = GridArquivadosDetalhadaMouseDown
            OnSelectCell = GridArquivadosDetalhadaSelectCell
            ColWidths = (
              64
              64
              64
              64
              64)
            RowHeights = (
              24
              24
              24
              24
              24)
          end
          object Panel11: TPanel
            Left = 1
            Top = 280
            Width = 615
            Height = 153
            Align = alBottom
            Color = 5395281
            ParentBackground = False
            TabOrder = 1
            object Label9: TLabel
              Left = 28
              Top = 39
              Width = 159
              Height = 18
              Caption = 'VALOR SELECIONADO (R$)'
              Color = 15790835
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clSilver
              Font.Height = 18
              Font.Name = 'Calibri'
              Font.Style = []
              ParentColor = False
              ParentFont = False
            end
            object Button7: TButton
              Left = 272
              Top = 56
              Width = 161
              Height = 27
              Caption = 'IMPRIMIR'
              TabOrder = 0
              OnClick = Button7Click
            end
            object EditArquivadosSelecionado: TEdit
              Left = 28
              Top = 63
              Width = 225
              Height = 48
              Color = 15790835
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = 40
              Font.Name = 'Calibri'
              Font.Style = []
              ParentFont = False
              ReadOnly = True
              TabOrder = 1
            end
            object Button13: TButton
              Left = 272
              Top = 88
              Width = 161
              Height = 27
              Caption = 'DESARQUIVAR'
              TabOrder = 2
              OnClick = Button13Click
            end
          end
        end
      end
    end
  end
  object SQLQuery1: TSQLQuery
    Params = <>
    Left = 1128
    Top = 64
  end
  object SaveDialog1: TSaveDialog
    Left = 1208
    Top = 64
  end
  object SQLConnection1: TSQLConnection
    Left = 1048
    Top = 64
  end
  object SQLQuery2: TSQLQuery
    Params = <>
    Left = 968
    Top = 64
  end
  object PrintDialog1: TPrintDialog
    Left = 896
    Top = 64
  end
end
